#include "main.h"

// concurrent server
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage:%s port\n",argv[0]);
        exit(1);
    }

    //variables
    int backlog = 10;
    int s_socket;
    int c_socket;
    struct sockaddr_in s_address, c_address;

    // memory resource
    char buffer[256];
    memset(buffer,0,256);
    
    //assign values to s_address
    //internet address
    s_address.sin_family = AF_INET;
    //ip address
    s_address.sin_addr.s_addr = INADDR_ANY;
    //port address
    s_address.sin_port = htons(atoi(argv[1]));

    // step 1 :- create socket
    if((s_socket = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        printf("\nServer socket creation error:\n\t");
        switch(errno) {
            case EACCES:
                printf("Permission to create a socket of the specified type and/or protocol is denied.");
                break;
            case EAFNOSUPPORT:
                printf("The implementation does not support the specified address family.");
                break;
            case EINVAL:
                printf("Unknown protocol, or protocol family not available.");
                break;
            case EMFILE:
                printf("The per-process limit on the number of open file descriptors has been reached.");
                break;
            case ENFILE:
                printf("The system-wide limit on the total number of open files has been reached.");
                break;
            case ENOBUFS:
            case ENOMEM:
                printf("Insufficient memory is available. The socket cannot be created until sufficient resources are freed.");
                break;
            case EPROTONOSUPPORT:
                printf("The protocol type or the specified protocol is not supported within this domain.");
                break;
            default: printf("Unknown error!");
        }
        printf("\n");
        exit(1);
    }

    // step 2 :- bind socket to address
    if((bind(s_socket,(struct sockaddr *)&s_address,sizeof(s_address))) != 0) {
        printf("\nServer socket address binding error:\n\t");
        switch(errno) {
            case EACCES:
                printf("The address is protected, and the user is not the superuser.");
                break;
            case EADDRINUSE:
                printf("The given address is already in use.");
                break;
            case EBADF:
                printf("Not a valid file descriptor.");
                break;
            case EINVAL:
                printf("The socket is already bound to an address.");
                break;
            case ENOTSOCK:
                printf("The file descriptor does not refer to a socket.");
                break;
            default: printf("Unknown error!");
        }
        printf("\n");
        exit(1);
    }

    
    pid_t pid;

    while(1) {

        // step 3 :- make socket listen for incoming connections
        if((listen(s_socket,backlog)) != 0) {
            printf("\nServer listen error:\n\t");
            switch(errno) {
                case EADDRINUSE:
                    printf("The given address is already in use.");
                    break;
                case EBADF:
                    printf("Not a valid file descriptor.");
                    break;
                case EOPNOTSUPP:
                    printf("The socket is not of a type that supports this operation.");
                    break;
                case ENOTSOCK:
                    printf("The file descriptor does not refer to a socket.");
                    break;
                default: printf("Unknown error!");
            }
            printf("\n");
            exit(1);
        }

        // step 4 :- accept connection depend on mode
        socklen_t addrlen = sizeof(c_address);
        c_socket = accept(s_socket,(struct sockaddr *)&c_address,&addrlen);
        if(c_socket < 0) {
            printf("\nServer accept error:\n\t");
            switch(errno) {
                case ENETDOWN:
                    printf("Network is down.");
                    break;
                case ENOPROTOOPT:
                    printf("Protocol not available.");
                    break;
                case EHOSTDOWN:
                    printf("Host is down.");
                    break;
                case ENONET:
                    printf("Machine is not on the network.");
                    break;
                case EHOSTUNREACH:
                    printf("Host is unreachable.");
                    break;
                case ENETUNREACH:
                    printf("Network unreachable.");
                    break;
                case ENOSR:
                    printf("No STREAM resources.");
                    break;
                case ESOCKTNOSUPPORT:
                    printf("Socket type not supported.");
                    break;
                case EPROTONOSUPPORT:
                    printf("Protocol not supported.");
                    break;
                case ETIMEDOUT:
                    printf("Connection timed out.");
                    break;
                case EAGAIN:
                    printf("The socket is marked nonblocking and no connections are present to be accepted.");
                    break;
                case EBADF:
                    printf("Not a valid file descriptor.");
                    break;
                case ECONNABORTED:
                    printf("A connection has been aborted.");
                    break;
                case EFAULT:
                    printf("The client address structure is not in a writable part of the user address space.");
                    break;
                case EINTR:
                    printf("The system call was interrupted by a signal that was caught before a valid connection arrived.");
                    break;
                case EINVAL:
                    printf("Socket is not listening for connections, or address structure length is invalid");
                    break;
                case EMFILE:
                    printf("The per-process limit on the number of open file descriptors has been reached.");
                    break;
                case ENFILE:
                    printf("The system-wide limit on the total number of open files has been reached.");
                    break;
                case ENOBUFS:
                case ENOMEM:
                    printf("Not  enough free memory.");
                    break;
                case ENOTSOCK:
                    printf("The file descriptor does not refer to a socket.");
                    break;
                case EOPNOTSUPP:
                    printf("The referenced socket is not of type SOCK_STREAM.");
                    break;
                case EPROTO:
                    printf("Protocol error.");
                    break;
                case EPERM:
                    printf("Firewall rules forbid connection.");
                    break;
                default: printf("Unknown error!");
            }
            printf("\n");
            exit(1);
        }

        if((pid = fork()) == 0) {

            //demo operations
            char str[] = "Hello from server\n";
            send(c_socket,str,sizeof(str),0);
            int cont;
            cont=recv(c_socket,buffer,256,0);
            write(1,buffer,cont);

            //step 5 :- close sockets
            if((close(s_socket)) != 0) {
                printf("\nServer close error:\n\t");
                switch(errno) {
                    case EBADF:
                        printf("Not a valid open file descriptor.");
                        break;
                    case EINTR:
                        printf("Interrupted by a signal.");
                        break;
                    case EIO:
                        printf("An I/O error occurred.");
                        break;
                    case ENOSPC:
                    case EDQUOT:
                        printf("Subsequent write exceeded storage space.");
                        break;
                    default: printf("Unknown error!");
                }
                printf("\n");
                exit(1);
            }
            return 0;
        }
    }
    return 0;
}
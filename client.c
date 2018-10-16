#include "main.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage:%s ip port\n",argv[0]);
        exit(1);
    } 

    // variables
    int c_socket;
    struct sockaddr_in c_address;

    // memory resource
    char buffer[256];

    //assign values to c_address
    //internet address
    c_address.sin_family = AF_INET;
    //ip address
    c_address.sin_addr.s_addr = inet_addr(argv[1]);
    //port address
    c_address.sin_port = htons(atoi(argv[2]));

    // step 1 :- create socket
    if((c_socket = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        printf("\nClient socket creation error:\n\t");
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

    // step 2 :- connect
    if(connect(c_socket,(struct sockaddr *)&c_address,sizeof(c_address)) == -1) {
        printf("\nSocket connecting error:\n\t");
        switch(errno) {
            case EACCES:
            case EPERM:
                printf("The user tried to connect to a broadcast address without having the socket broadcast flag enabled or the connection request failed because of a local firewall rule.");
                break;
            case EADDRINUSE:
                printf("Local address is already in use.");
                break;
            case EADDRNOTAVAIL:
                printf("The socket had not previously been bound to an address and, upon attempting to bind it to an ephemeral port, it was determined that all port numbers in the ephemeral port range are currently in use.");
                break;
            case EAFNOSUPPORT:
                printf("The passed address didn't have the correct address family.");
                break;
            case EAGAIN:
                printf("Insufficient entries in the routing cache.");
                break;
            case EALREADY:
                printf("The socket is nonblocking and a previous connection attempt has not yet been completed.");
            case EBADF:
                printf("Not a valid open file descriptor.");
                break;
            case ECONNREFUSED:
                printf("Stream socket found no one listening on the remote address.");
                break;
            case EFAULT:
                printf("The socket structure address is outside the user's address space.");
                break;
            case EINPROGRESS:
                printf("The socket is nonblocking and the connection cannot be completed immediately.");
                break;
            case EINTR:
                printf("The system call was interrupted by a signal that was caught.");
                break;
            case EISCONN:
                printf("The socket is already connected.");
                break;
            case ENETUNREACH:
                printf("Network is unreachable.");
                break;
            case ENOTSOCK:
                printf("The file descriptor does not refer to a socket.");
                break;
            case EPROTOTYPE:
                printf("The socket type does not support the requested communications protocol.");
                break;
            case ETIMEDOUT:
                printf("Timeout while attempting connection.");
                break;            
            default: printf("Unknown error!");
        }
        printf("\n");
        exit(1);
    }

    //demo operations
    int cont=recv(c_socket,buffer,256,0);
    write(STDOUT_FILENO,buffer,cont);
    char str[256];
    printf("Enter message to send to server:\n");
    scanf("%s",str);
    send(c_socket,str,sizeof(str),0);

    //step 3 :- close socket
    if((close(c_socket)) != 0) {
        printf("\nClient close error:\n\t");
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
#include "main.h"

void server(unsigned int mode,unsigned int port) {
    //variables
    int s_socket;
    struct sockaddr_in s_address;

    //assign values to s_address
    //internet address
    s_address.sin_family = AF_INET;
    //ip address
    //TODO: make ip address dynamic
    s_address.sin_addr.s_addr = INADDR_ANY;
    //port address
    s_address.sin_port = htons(port);

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
                printf("The per-process limit on the number of open file descriptors has been reached.");
                break;
            case ENOBUFS:
            case ENOMEM:
                printf("Insufficient memory is available.  The socket cannot be created until sufficient resources are freed.");
                break;
            case EPROTONOSUPPORT:
                printf("The protocol type or the specified protocol is not supported within this domain.");
                break;
            default: printf("Unknown error!");
        }
        printf("\n");
    }

    // step 2 :- bind socket to address
    if((bind(s_socket,(struct sockaddr *)&s_address,sizeof(s_address))) != 0) {
        printf("\nServer socket address binding error:\n\t");
        //TODO: solve error with errno
    }
}
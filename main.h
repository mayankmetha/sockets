// POSIX standards
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200809L

// Headers
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>

void server(unsigned int mode,unsigned int port);
void client(unsigned int mode,unsigned int port);
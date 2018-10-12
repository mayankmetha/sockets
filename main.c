// POSIX standards
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200809L

// Headers
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

// Global variables
unsigned int mode = 0;

void server(unsigned int mode) {
    // Server code goes here
    printf("Server\n");
}

void client(unsigned int mode) {
    // Client code goes here
    printf("Client\n");
}

void commandError() {
    // Command usage error message
    printf("Error using command\n");
}

// main
int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-m") == 0) {
            i++;
            if(argv[i] != NULL) {
                // 1 - iterative mode
                // 2 - concurrent mode
                mode = atoi(argv[i]);
                printf("mode:%d\n",mode);
            } else {
                commandError();
            }
        } else if(strcmp(argv[i], "-s") == 0) {
            // Run as server
            server(mode);
        } else if(strcmp(argv[i], "-c") == 0) {
            // Run as client
            client(mode); 
        } else {
            commandError();
        }
    }
}
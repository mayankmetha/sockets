#include "main.h"

void commandError() {
    // Command usage error message
    printf("Error using command\n");
}

// main
int main(int argc, char *argv[]) {
    //variables 
    unsigned int mode = 0;
    unsigned int port = 8080;
    unsigned int operation = 0;
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
        } else if(strcmp(argv[i], "-p") == 0) {
            i++;
            if(argv[i] != NULL) {
                // port number
                port = atoi(argv[i]);
            } else {
                commandError();
            }
        } else if(strcmp(argv[i], "-s") == 0) {
            // Run as server
            operation = 1;
        } else if(strcmp(argv[i], "-c") == 0) {
            // Run as client
            operation = 2;
        } else {
            commandError();
        }
    }
    if(operation == 1) {
        server(mode,port);
    } else if(operation == 2) {
        client(mode,port);
    }
}
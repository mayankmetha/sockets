#include "main.h"

void commandError(int type) {
    // Command usage error message
    if(type) 
        printf("Error using command!\n");
    printf("Usage:\n\t./socket [-s|-c|-h|--help] [-p (port number)] [-m (mode)]\n");
    printf("Options:\n\t-s\t\t\tserver mode");
    printf("\n\t-c\t\t\tclient mode");
    printf("\n\t-h | --help\t\thelp");
    printf("\n\t-p (port number)\tport number");
    printf("\n\t-m 1\t\t\titerative mode (Server only)");
    printf("\n\t-m 2\t\t\tconcurrent mode(Server only)\n");
    exit(1);
}

// main
int main(int argc, char *argv[]) {
    //variables 
    unsigned int mode = 0;
    unsigned int port = 8080;
    int operation = -1;
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-m") == 0) {
            i++;
            if(argv[i] != NULL) {
                // 1 - iterative mode
                // 2 - concurrent mode
                mode = atoi(argv[i]);
                printf("mode:%d\n",mode);
            } else {
                commandError(1);
            }
        }
        if(strcmp(argv[i], "-p") == 0) {
            i++;
            if(argv[i] != NULL) {
                // port number
                port = atoi(argv[i]);
            } else {
                commandError(1);
            }
        }
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            //Display help menu
            operation = 0;
        } else if(strcmp(argv[i], "-s") == 0) {
            // Run as server
            operation = 1;
        } else if(strcmp(argv[i], "-c") == 0) {
            // Run as client
            operation = 2;
        } else {
            commandError(1);
        }
    }
    if(operation == 0) {
        commandError(0);
    } else if(operation == 1) {
        server(mode,port);
    } else if(operation == 2) {
        client(port);
    } else {
        commandError(1);
    }
}
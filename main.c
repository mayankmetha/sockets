#include "main.h"

char *cmd;

void commandError(int type) {
    // Command usage error message
    if(type) 
        printf("Error using command!\n");
    printf("Usage:\n\t%s -s|-c|-h|--help [-i (ipv4 address)] [-p (port number)] [-m (mode)]\n",cmd);
    printf("Options:\n\t-s\t\t\tserver mode");
    printf("\n\t-c\t\t\tclient mode");
    printf("\n\t-h | --help\t\thelp");
    printf("\n\t-p (port number)\tport number");
    printf("\n\t-i (ipv4 address)\tipv4 address(Client only)");
    printf("\n\t-m 1\t\t\titerative mode (Server only)");
    printf("\n\t-m 2\t\t\tconcurrent mode(Server only)\n");
    exit(1);
}

// main
int main(int argc, char *argv[]) {
    //variables 
    unsigned int mode = 1;
    unsigned int port = 8080;
    char *ip = "127.0.0.1";
    int operation = 0;
    cmd = argv[0];
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            //Display help menu
            operation = 0;
            break;
        } else if(strcmp(argv[i], "-s") == 0) {
            // Run as server
            operation = 1;
            break;
        } else if(strcmp(argv[i], "-c") == 0) {
            // Run as client
            operation = 2;
            break;
        } else {
            commandError(1);
        }
    }

    if(operation == 0) {
        commandError(0);
    } else if(operation == 1) {
        for(int i = 1; i < argc; i++) {
            if(strcmp(argv[i], "-m") == 0) {
                if(argv[i++] != NULL) {
                    // 1 - iterative mode
                    // 2 - concurrent mode
                    mode = atoi(argv[i]);
                } else {
                    commandError(1);
                }
            }
            if(strcmp(argv[i], "-p") == 0) {
                if(argv[i++] != NULL) {
                    // port number
                    port = atoi(argv[i]);
                } else {
                    commandError(1);
                }
            }
        }
        server(mode,port);
    } else if(operation == 2) {
        for(int i = 1; i < argc; i++) {
            if(strcmp(argv[i], "-i") == 0) {
                if(argv[i++] != NULL) {
                    // ip address
                    ip = argv[i];
                } else {
                    commandError(1);
                }
            }
            if(strcmp(argv[i], "-p") == 0) {
                if(argv[i++] != NULL) {
                    // port number
                    port = atoi(argv[i]);
                } else {
                    commandError(1);
                }
            }
        }
        client(port,ip);
    } else {
        commandError(1);
    }
}
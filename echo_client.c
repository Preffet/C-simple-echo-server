#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>

// e.g. run as: ./echo_client 127.0.0.1 port

#define BUF_SIZE 16

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage: %s server_addr port\n", argv[0]);
        printf("server_addr is server IP address (e.g. 127.0.0.1)\n");
        printf("port is a positive number in the range 1025 to 65535\n");
        exit(1);
    }
    
    char* server_addr = argv[1];
    uint16_t port = atoi(argv[2]);

    struct sockaddr_in server;
    char echo_buf[BUF_SIZE];

    // create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(struct sockaddr_in));  

    // Set the server information
    server.sin_family = AF_INET;            /* Internet address family */
    server.sin_port = htons(port);          /* Server port */

    // set server address using inet_aton
    if (!inet_aton(server_addr, &server.sin_addr)) {
        perror("invalid server address");
        exit(EXIT_FAILURE);
    }

    // run until the client enters a "."
    while (echo_buf[0] != '.') {
        printf("please enter the message to send: ");
        fgets(echo_buf, BUF_SIZE, stdin);
      
        //send the message (echo_buf)) to the server using sockfd
        ssize_t bytes = sendto(sockfd, echo_buf, BUF_SIZE, 0, 
                         (struct sockaddr*) &server, 
                         sizeof(struct sockaddr_in));
                        
        if (bytes != BUF_SIZE) {
            perror("sendto failed");
            close (sockfd);
            exit(EXIT_FAILURE);
        } 
        
        printf("client sent %zd bytes to server\n", bytes);
    }
    
    echo_buf[1] = '\0';
    printf("client entered %s, exiting ...\n", echo_buf);
    close(sockfd); 
}



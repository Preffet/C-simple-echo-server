#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 16

// run as: ./server port

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: %s port\n", argv[0]);
        printf("port should be a number between 1025 and 65535\n");
        exit(1);
    }

    struct sockaddr_in server;
    struct sockaddr_in client;
    char echo_buf[BUF_SIZE];
    echo_buf[0] = '\0';
    
    int port = atoi(argv[1]);

    // create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); 

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&server, 0, sizeof(struct sockaddr_in));
    memset(&client, 0, sizeof(struct sockaddr_in));
    
    // Set the server information
    server.sin_family = AF_INET;                 /* Internet address family */
    server.sin_port = htons(port);               /* Port number */
    server.sin_addr.s_addr = htonl(INADDR_ANY);  /* Any incoming interface */
     
    // bind server address to the socket
    if (bind(sockfd, (struct sockaddr*) &server, sizeof(struct sockaddr_in))) {
        perror("bind failed");
        close(sockfd); 
        exit(EXIT_FAILURE);
    }
  
    /* run until the client sends a string beginning . */
    while (echo_buf[0] != '.') {
        printf("waiting ...\n");
        socklen_t len = (socklen_t) sizeof(struct sockaddr_in);
       
        //receive a message from a socket  
        ssize_t bytes = recvfrom(sockfd, echo_buf, BUF_SIZE, 0, 
                            (struct sockaddr*) &client, &len);
                            
        if (bytes != BUF_SIZE) {
            perror("server recvfrom error");
            exit(EXIT_FAILURE);
        }
            
        if (echo_buf[0] != '.') {
            printf("server received %zd bytes:\n", bytes);
            printf("%s", echo_buf);
            printf("--------------------------\n");
        }        
    }
    
    echo_buf[1] = '\0';
    printf("server received %s, exiting ...\n", echo_buf);
    close(sockfd); 
}
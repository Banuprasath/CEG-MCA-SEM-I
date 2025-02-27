#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], response[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Enter a paragraph:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, response, sizeof(response), 0);

    printf("Server Response: %s\n", response);

    close(sock);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void count_text(char *text, int *lines, int *words, int *letters) {
    *lines = *words = *letters = 0;
    int i = 0, in_word = 0;

    while (text[i]) {
        if (text[i] == '\n')
            (*lines)++;
        if (text[i] != ' ' && text[i] != '\n' && text[i] != '\t') {
            (*letters)++;
            in_word = 1;
        } else if (in_word) {
            (*words)++;
            in_word = 0;
        }
        i++;
    }
    if (in_word) (*words)++;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];
    int lines, words, letters;
    char result[100];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);

    printf("Server is waiting for connection...\n");
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    printf("Client connected!\n");

    recv(new_socket, buffer, sizeof(buffer), 0);
    count_text(buffer, &lines, &words, &letters);
    sprintf(result, "Lines: %d, Words: %d, Letters: %d", lines, words, letters);
    send(new_socket, result, strlen(result), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}

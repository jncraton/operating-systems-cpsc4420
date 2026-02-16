#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(2001);

    if (bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(listen_sock);
        return 1;
    }

    if (listen(listen_sock, 1) < 0) {
        perror("listen");
        close(listen_sock);
        return 1;
    }

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int conn = accept(listen_sock, (struct sockaddr *)&client, &client_len);
    if (conn < 0) {
        perror("accept");
        close(listen_sock);
        return 1;
    }

    printf("Connected by %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    char buf[1024];
    while (1) {
        ssize_t n = recv(conn, buf, sizeof(buf), 0);
        if (n <= 0) break;
        if (send(conn, buf, n, 0) < 0) break;
    }

    close(conn);
    close(listen_sock);
    return 0;
}

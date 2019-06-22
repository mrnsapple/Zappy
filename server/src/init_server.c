/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** init_server
*/

#include "../include/init_server.h"

int init_listen(int fd, int client_nb, char **team_names)
{
    int teams = 0;
    for (int i = 0;team_names[i] != NULL; i++) 
        teams++;
    int max_number = teams * client_nb;
    if (listen(fd, max_number) < 0) {
        perror("Listening failed");
        return (-1);
    }
    return (0);
}

int init_socket(void)
{
    int sockfd;
    int sockopt;
    int nm = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return (-1);
    }
    sockopt = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &nm, sizeof(nm));
    if (sockopt < 0) {
        perror("Socket options failed");
        return (-1);
    }
    return (sockfd);
}

int init_bind_address(struct sockaddr_in address, int fd)
{
    // struct sockaddr_in address;
    int bindRes;

    // address.sin_family = AF_INET;
    // address.sin_port = htons(port);
    // address.sin_addr.s_addr = INADDR_ANY;
    bindRes = bind(fd, (struct sockaddr*)&address, sizeof(address));
    if (bindRes == -1) {
        perror("socket binding failed");
        return (-1);
    }
    return (0);
}

int init_select(fd_set *readFds)
{   
    struct timeval time = {.tv_sec = 0.000000001, .tv_usec = 1};
    if (select(FD_SETSIZE, readFds, NULL, 0,  &time) < 0) {
        perror("Select failed");
        return (-1);
    }
    return (0);
}

int init_accept(server_t *serv)
{
    int addrlen = sizeof(serv->sock->dest);
    int sock;

    sock = accept(serv->sock->fd, (struct sockaddr*)&serv->sock->address, (socklen_t*)&addrlen);
    if (sock < 0) {
        perror("accepting failed");
        return (-1);
    }
    return (sock);
}

socket_t *init_server(server_t *serv)
{
    socket_t *sock = malloc(sizeof(socket_t));

    if (sock == NULL)
        return (NULL);
    sock->teams = NULL;
    sock->fd = init_socket();
    if (sock->fd == -1)
        return (NULL);
    sock->address.sin_family = AF_INET;
    sock->address.sin_port = htons(serv->port);
    sock->address.sin_addr.s_addr = INADDR_ANY;
    if (init_bind_address(sock->address, sock->fd) == -1)
        return (NULL);
    return (sock);
}
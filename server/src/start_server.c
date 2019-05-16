/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** start_server
*/

#include "../include/init_server.h"
#include "../include/server.h"

char *read_user(int fd)
{
    char buff[1024];
    char *str;
    // char *

    // fflush(stdin);
    bzero(buff, 1024);
    if (read(fd, buff, 1024) < 0)
        return (NULL);
    str = strdup(buff);
    return (str);
}

void get_connections(server_t *serv)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, &serv->sock->readFds)) {
            if (i == serv->sock->fd) {
                serv->sock->client = init_accept(serv);
                serv->pid = fork();
                if (serv->pid == 0) {
                    printf("new connection %s\n", inet_ntoa(serv->sock->dest.sin_addr));
                    printf("%s\n", read_user(serv->sock->client));
                }
            }
        }
    }
}

void start_server(server_t *serv)
{
    while (1) {
        serv->sock->readFds = serv->sock->fds;
        // printf("here\n");
        init_select(serv->sock->readFds);
        // printf("here\n");
        get_connections(serv);
    }
    close(serv->sock->fd);
}
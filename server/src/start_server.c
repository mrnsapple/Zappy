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
                    printf("new connection %s:%d\n", inet_ntoa(serv->sock->dest.sin_addr), ntohs(serv->sock->dest.sin_port));
                    write(serv->sock->client, "Welcome\n", 9);
                    printf("%s", read_user(serv->sock->client));
                }
            }
        }
    }
}

void start_server(server_t *serv)
{
    while (1) {
        serv->sock->readFds = serv->sock->fds;
        init_select(serv->sock->readFds);
        get_connections(serv);
    }
    close(serv->sock->fd);
}
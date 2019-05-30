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

    bzero(buff, 1024);
    if (read(fd, buff, 1024) < 0)
        return (NULL);
    str = strdup(buff);
    return (str);
}

char *remove_char(char *str, char x)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == x)
            str[i] = '\0';
    return (str);
}

int check_name(server_t *serv, char *clientName)
{
    clientName = remove_char(clientName, '\n');
    for (int i = 0; serv->team_names != NULL; i++)
        if (strcmp(serv->team_names[i], clientName))
            return (1);
    return (0);
}

void user_interaction(server_t *serv)
{
    if (serv->pid == 0) {
        printf("new connection %s:%d\n", inet_ntoa(serv->sock->dest.sin_addr), ntohs(serv->sock->dest.sin_port));
        write(serv->sock->client, "WELCOME\n", 9);
        if (check_name(serv, read_user(serv->sock->client)) == 1) {
            char str[10];
            sprintf(str, "%d\n%d %d\n", serv->client_nb, serv->width, serv->height);
            write(serv->sock->client, str, sizeof(str));
            serv->client_nb -= 1;
        } else {
            write(serv->sock->client, "ko\n", 4);
        }
    }
}

void get_connections(server_t *serv)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, &serv->sock->readFds)) {
            if (i == serv->sock->fd) {
                serv->sock->client = init_accept(serv);
                serv->pid = fork();
                user_interaction(serv);
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
/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** start_server
*/

#include "../include/init_server.h"
#include "../include/server.h"
#include "../include/error_management.h"
#include "../include/client_management.h"

char *remove_char(char *str, char x)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == x)
            str[i] = '\0';
    return (str);
}

char *remove_spaces(char *str)
{
    for (int i = 0; str && str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
    return (str);
}

char *get_team_name(char **team_names, int client_fd)
{
    //printf("new connection %s:%d\n", inet_ntoa(serv->sock->dest.sin_addr), ntohs(serv->sock->dest.sin_port));
    char *team_name;

    write_to_fd(client_fd, "WELCOME\n");
    team_name = remove_spaces(read_user(client_fd));
    
    for (int i = 0; team_names != NULL && team_names[i] != NULL; i++)
        if (strcmp(team_names[i], team_name) == 0)
            return (team_name);
    write_to_fd(client_fd, "ko\n");
    return (NULL);
    /*if (check_name(serv, read_user(serv->sock->client)) == 1) {
        char str[10];
        sprintf(str, "%d\n%d %d\n", serv->client_nb, serv->width, serv->height);
        write(serv->sock->client, str, sizeof(str));
        serv->client_nb -= 1;
    } else {
        write(serv->sock->client, "ko\n", 4);
    }*/
}

void get_connections(server_t *serv)
{
    int fd;
    char *team_name;

    for (int i = 0; i < FD_SETSIZE; i++)
        if (FD_ISSET(i, &serv->sock->readFds) && i == serv->sock->fd) {
            fd = init_accept(serv);
            team_name = get_team_name(serv->team_names, fd);
            printf("fd:%d, team_name:%s\n", fd, team_name);
            init_client(serv, fd, team_name);
            client_interaction(serv);
            //serv->sock->client = init_accept(serv);
            //serv->pid = fork();
            //user_interaction(serv);
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
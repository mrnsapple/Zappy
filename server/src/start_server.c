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
    
}

void get_connections(server_t *serv)
{
    int fd;
    char *team_name;

    //for (int i = 0; i < FD_SETSIZE; i++)
    if (FD_ISSET(serv->sock->fd, &serv->sock->readFds)) {
        printf("oscarillo and oscafrinestail\n");
        fd = init_accept(serv);
        printf("afteraccept\n");
        team_name = get_team_name(serv->team_names, fd);
        printf("fd:%d, team_name:%s\n", fd, team_name);
        init_client(serv, fd, team_name);
        //serv->sock->client = init_accept(serv);
        //serv->pid = fork();
        //user_interaction(serv);
    }

}

void fd_stuff(server_t *serv)
{
    teams_t *teams = serv->sock->teams;
    client_id_t *clients;

    FD_ZERO (&(serv->sock->readFds));
    FD_SET (serv->sock->fd, &(serv->sock->readFds));
    for (; teams != NULL; teams = teams->next) {
        clients = teams->clients;
        for (; clients != NULL; clients = clients->next)
            FD_SET (clients->fd, &(serv->sock->readFds));

    }
}

void start_server(server_t *serv)
{
    while (42) {
        serv->sock->readFds = serv->sock->fds;
        fd_stuff(serv);
    
        printf("initselect\n");
        init_select(serv->sock->readFds);
        printf("beforegetconections\n");
        client_interaction(serv);
        get_connections(serv);
        printf("aftergetconections\n");

    }
    close(serv->sock->fd);
}
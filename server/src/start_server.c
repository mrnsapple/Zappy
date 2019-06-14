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

void fd_stuff(server_t *serv)
{
    teams_t *teams = serv->sock->teams;
    client_id_t *clients;

    FD_ZERO(&serv->sock->readFds);
    FD_SET(serv->sock->fd, &serv->sock->readFds);
    serv->sock->max_sd = serv->sock->fd;
        
    for (int i = 0; i < serv->client_nb; i++) {
        serv->sock->sd = serv->socket_client[i];
        if (serv->sock->sd > 0)
            FD_SET(serv->sock->sd, &serv->sock->readFds);
        if (serv->sock->sd > serv->sock->max_sd)
            serv->sock->max_sd = serv->sock->sd;
    }
    
    for (; teams != NULL; teams = teams->next) {
        clients = teams->clients;
        for (; clients != NULL; clients = clients->next)
            FD_SET (clients->fd, &(serv->sock->readFds));
    }
}

void get_connections(server_t *serv)
{
    int fd;
    char *team_name;

    //for (int i = 0; i < FD_SETSIZE; i++)
    if (FD_ISSET(serv->sock->fd, &serv->sock->readFds)) {
        printf("Awaiting for a new connection\n");
        fd = init_accept(serv);
        printf("Connection with fd %d has been accepted\n", fd);
        team_name = get_team_name(serv->team_names, fd);
        printf("fd:%d, team_name:%s\n", fd, team_name);
        init_client(serv, fd, team_name);
        
        for (int i = 0; i < serv->client_nb; i++) {
            if (serv->socket_client[i] == 0) {
                serv->socket_client[i] = fd;
                printf("%d added to the list of sockets, now %d total\n", fd, i + 1);
                break;
            }
        }
    }
    for (int i = 0; i < serv->client_nb; i++) {
        serv->sock->sd = serv->socket_client[i];
        printf("here yo go\n");
        if (FD_ISSET(serv->sock->sd, &serv->sock->readFds)) {
            // client_interaction(serv);
            printf("now it's here\n");
            printf("user sent -> %s\n", read_user(fd));
            
        }
    }
}

void start_server(server_t *serv)
{
    while (42) {
        fd_stuff(serv);
        init_select(serv->sock->readFds, serv->sock->max_sd);
        // printf("Select Initialization is done, comencing client interaction\n");
        get_connections(serv);
        // client_interaction(serv);
        // printf("get connections achieved\n");
    }
    close(serv->sock->fd);
}
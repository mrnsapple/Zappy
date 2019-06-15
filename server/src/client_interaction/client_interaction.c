/*
** EPITECH PROJECT, 2019
** client interaction
** File description:
** client_interaction
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"
#include "../../include/init_server.h"
#include "../../include/server.h"
#include "../../include/error_management.h"

void    send_map_size(server_t *serv, teams_t *teams, client_id_t *clients)
{
    char str[10];
    
    clients->send_map_size = 0;
    sprintf(str, "%d\n%d %d\n", serv->client_nb - teams->clients_in_team, serv->width, serv->height);
    write_to_fd(clients->fd, str);
}

int    client_actions(server_t *serv, teams_t *teams, client_id_t *clients)
{
    char *result;

    if (! FD_ISSET(clients->fd, &serv->sock->readFds)) {
        printf("returns 0\n");
        return 0;
    }
    printf("inclient action\n\n");
    if (clients->send_map_size == 1)
       send_map_size(serv, teams, clients);
    printf("before read\n");
    result = read_user(clients->fd);
    printf("after read\n");
    connect_number(result, serv, teams, clients);
    inventory(result, serv, teams, clients);
    printf("result:%s\n", result);
    printf("team_name:%s, fd:%d\n", clients->team_name, clients->fd);
    return (0);  
}

void    client_interaction(server_t *serv)
{
    teams_t *teams = serv->sock->teams;
    client_id_t *clients;

    for (; teams != NULL; teams = teams->next) {
        clients = teams->clients;
        for (; clients != NULL; clients = clients->next)
            client_actions(serv, teams, clients);
    }
}   

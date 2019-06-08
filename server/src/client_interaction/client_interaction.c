/*
** EPITECH PROJECT, 2019
** client interaction
** File description:
** client_interaction
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"


void    client_interaction(server_t *serv)
{
    teams_t *teams = serv->sock->teams;
    client_id_t *clients;

    for (; teams != NULL; teams = teams->next) {
        clients = teams->clients;
        for (; clients != NULL; clients = clients->next)
            printf("team_name:%s, fd:%d\n", clients->team_name, clients->fd);
    }
}   

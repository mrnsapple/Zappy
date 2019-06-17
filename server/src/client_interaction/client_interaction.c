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
    char *read_result;

    serv->to_write="ko\n";
    printf("inclient action\n\n");
    if (clients->send_map_size == 1)
       send_map_size(serv, teams, clients);
    printf("before read\n");
    read_result = read_user(clients->fd);
    printf("after read\n");
    connect_number(read_result, serv, teams, clients);
    inventory(read_result, serv, clients);
    forward(read_result, serv, teams, clients);
    
    write_to_fd(clients->fd, serv->to_write);

    printf("read_result:%s, response:%s:\n", read_result, serv->to_write);
    printf("team_name:%s, fd:%d\n", clients->team_name, clients->fd);
    return (0);
}

void    client_interaction(server_t *serv)
{
    teams_t *teams = serv->sock->teams;
    client_id_t *clients;
    //printf("ualala\n");
    for (; teams != NULL; teams = teams->next) {
        //printf("there is a team\n");
        clients = teams->clients;
        for (; clients != NULL; clients = clients->next) {
            //if (fd == clients->fd) {
                //printf("in clien action\n");
                client_actions(serv, teams, clients);
            //}
        }
    }
}

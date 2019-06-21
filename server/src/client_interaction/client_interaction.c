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

    serv->to_write=strdup("ko\n");
    // printf("inclient action\n\n");
    if (clients->send_map_size == 1)
       send_map_size(serv, teams, clients);
    read_result = read_user(clients->fd);
    if (strcmp(read_result, "DELETE CLIENT") == 0)
        return (delete_client(serv, clients->fd));
    if (rand() % 3 == 0)
        add_item_to_client(clients, "food\n", 0);

    printf("after read:%s\n", read_result);
    connect_number(read_result, serv, teams, clients);
    inventory(read_result, serv, clients);
    forward(read_result, serv, clients);
    look(read_result, serv, clients);
    take(read_result, serv, clients);
    right(read_result, serv, clients);
    left(read_result, serv, clients);
    //write_to_fd(clients->fd, "ko\n");
    write_to_fd(clients->fd, serv->to_write);

    // printf("read_result:%s, response:%s:\n", read_result, serv->to_write);
    // printf("team_name:%s, fd:%d\n", clients->team_name, clients->fd);

    return (0);
}

int    client_interaction(server_t *serv)
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
            //printf("is dead:%d\n", clients->is_dead);
            if (clients->is_dead == 0 && client_actions(serv, teams, clients) == 5)
                return (2);
            //}
        }
    }
    return (0);
}

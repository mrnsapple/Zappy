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
#include "../../include/map.h"
#include "../../include/error_management.h"

int delete_from_map(client_id_t **player, int client_fd)
{
    int val = 0;

    if (player == NULL)
        return (0);
    for (int i = 0; player != NULL && player[i] != NULL; i++) {
        if (player[i]->fd == client_fd)
            val = 1;
        //if (val == 1 && player[i + 1] == NULL) {
        //    player = NULL;
        //    return (0);
        //}
        if (val >= 1) {
           player[i] = player[i + 1];
           val++;
        }
    }
    return (0);
}

int delete_client_from_list(teams_t *teams, client_id_t *client, client_id_t *prev_client)
{
    if (teams == NULL)
        return (0);
    else if (prev_client == NULL) {
        printf("entr elsif\n");
        teams->clients = client->next;
    }
    else
        prev_client = client->next;
    if (teams->clients == NULL)
        teams = NULL;
    return (0);
}

int  delete_client(server_t *serv, int client_fd)
{
    client_id_t *prev_clients = NULL;

    printf("maybe client stoped,id:%d\n", client_fd);
    //exit (0);
    close(client_fd);
    /* for (int y = 0; serv->map[y] != NULL; y++)
        for (int x = 0; (serv->map[y][x]).is_last == 0; x++)
            delete_from_map(serv->map[y][x].player, client_fd);
    printf("second for\n");
    */
    for (teams_t *teams = serv->sock->teams; teams != NULL; teams = teams->next)
        for (client_id_t *clients = teams->clients; clients != NULL; clients = clients->next) {
            if (client_fd == clients->fd && clients->is_dead == 0) {
                teams->clients_in_team--;
                clients->is_dead=1;
                //delete_client_from_list(serv->sock->teams, clients, prev_clients);
                //return (5);
                //printf("in clien action\n");
            }
            prev_clients = clients;
        }
    //  fd_stuff(serv);
    return (5);
}
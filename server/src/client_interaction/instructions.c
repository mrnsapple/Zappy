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

void    connect_number(char *result, server_t *serv,  teams_t *teams, client_id_t *clients)
{
    char char_arr [100];

    if (strcmp(result, "Connect_nbr\n") == 0) {
        sprintf(char_arr, "%d", serv->client_nb - teams->clients_in_team);
        write_to_fd(clients->fd, char_arr);
    }
}
/*
void    inventory(char *result, server_t *serv,  teams_t *teams, client_id_t *clients)
{
    char *str = "";

    if (strcmp(result, "Inventory\n") == 0) {
        //sprintf(str, "%d", serv->client_nb - teams->clients_in_team);
        write_to_fd(clients->fd, str);
    }  
}*/
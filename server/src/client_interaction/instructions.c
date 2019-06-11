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

int    inventory(char *result, server_t *serv,  teams_t *teams, client_id_t *clients)
{
    char str[200];// = "[ ";
    char char_arr [100];

    if (strcmp(result, "Inventory\n") != 0)
        return 0;
    strcpy(str,"[ ");
    for (int i = 0; strcmp(clients->items[i].name, "end") != 0; i++) {
        printf("item:%s, %d\n", clients->items[i].name, strcmp(clients->items[i].name, "end"));
        strcat(str, clients->items[i].name);
        strcat(str, " ");
        sprintf(char_arr, "%d", clients->items[i].amount);
        strcat(str, char_arr);
        if (strcmp(clients->items[i + 1].name, "end") != 0)
            strcat(str, ",");
        strcat(str, " ");
    }
    strcat(str, "]");
    printf("the str:%s\n", str);
    write_to_fd(clients->fd, str);
    return (0);
}
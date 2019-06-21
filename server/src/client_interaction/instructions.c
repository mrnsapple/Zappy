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

pos_t   get_position(map_t ** map, client_id_t *clients)
{
    pos_t pos = {-1, -1, -1};

    for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; (map[y][x]).is_last == 0; x++)
            for (int i = 0; map[y][x].player != NULL && map[y][x].player[i] != NULL; i++)
                if (map[y][x].player[i]->fd == clients->fd) {
                    pos.x = x;
                    pos.y = y;
                    pos.i = i;
                //printf("this player wants to move\n");
                }
    return (pos);
}

void    connect_number(char *result, server_t *serv,  teams_t *teams, client_id_t *clients)
{
    char char_arr [100];

    if (strcmp(result, "Connect_nbr\n") == 0) {
        sprintf(char_arr, "%d", serv->client_nb - teams->clients_in_team);
        serv->to_write = strdup(char_arr);
    }
}

int    inventory(char *result, server_t *serv, client_id_t *clients)
{
    char str[200];// = "[ ";
    char char_arr [100];

    if (strcmp(result, "Inventory\n") != 0)
        return (0);
    for (float i = 0; i != (float)(1 / serv->freq); i++);    
    strcpy(str,"[ ");
    for (int i = 0; strcmp(clients->items[i].name, "end") != 0; i++) {
        //printf("item:%s, %d\n", clients->items[i].name, strcmp(clients->items[i].name, "end"));
        strcat(str, clients->items[i].name);
        strcat(str, " ");
        sprintf(char_arr, "%d", clients->items[i].amount);
        strcat(str, char_arr);
        if (strcmp(clients->items[i + 1].name, "end") != 0)
            strcat(str, ",");
        strcat(str, " ");
    }
    strcat(str, "]");
    //printf("the str:%s\n", str);
    serv->to_write = strdup(str);
    return (0);
}

int right(char *result, server_t *serv, client_id_t *clients)
{
    if (strcmp(result, "Right\n") != 0)
        return (0);
    for (float i = 0; i != (float)(7 / serv->freq); i++);
    int new_direc = clients->direction + 1;
    if (new_direc > 3)
        new_direc = UP;
    clients->direction = new_direc;
    printf("client move head right to direction %d\n", clients->direction);
    serv->to_write = "ok";    
    return (0);
}

int left(char *result, server_t *serv, client_id_t *clients)
{
    if (strcmp(result, "Left\n") != 0)
        return (0);
    for (float i = 0; i != (float)(7 / serv->freq); i++);
    int new_direc = clients->direction - 1;
    if (new_direc < 0)
        new_direc = LEFT;
    clients->direction = new_direc;
    printf("client move head left to direction %d\n", clients->direction);
    serv->to_write = "ok";    
    return (0);
}

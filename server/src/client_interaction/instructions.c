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
        serv->to_write = char_arr;
    }
}
//int 
int    inventory(char *result, server_t *serv,  teams_t *teams, client_id_t *clients)
{
    char str[200];// = "[ ";
    char char_arr [100];

    if (strcmp(result, "Inventory\n") != 0)
        return 0;
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
    serv->to_write = str;
    return (0);
}

int forward(char *result, server_t *serv, teams_t *teams, client_id_t *clients)
{
    if (strcmp(result, "Forward\n") == 0) {
        printf("client pos %d,%d\n", clients->pos_x, clients->pos_y);
        
        // if (clients->direction == UP) {
        //     int new_pos_x = clients->pos_x - 1;
            
        //     serv->map[new_pos_x][clients->pos_y].player[0] = clients;
        //     serv->map[clients->pos_x][clients->pos_y].player[0] = NULL;
        //     clients->pos_x = new_pos_x;
        // }
        for (int y = 0; serv->map[y] != NULL; y++) {
            for (int x = 0; (serv->map[y][x]).is_last == 0; x++) {
                for (int i = 0; serv->map[y][x].player != NULL && serv->map[y][x].player[i] != NULL; i++) {
                    if (serv->map[y][x].player[i]->fd == clients->fd) {
                        printf("this player wants to move\n");
                    }
                }
                // if (serv->map[y][x].player == NULL)
                    // printf("x");
                // else
                    // printf("o");
            //display_items(map[y][x].items);
            }
            printf("\n");
        }
    
    }
    return (0);
}
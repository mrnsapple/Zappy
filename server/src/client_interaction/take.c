/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** take
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"
#include "../../include/init_server.h"
#include "../../include/server.h"
#include "../../include/map.h"
#include "../../include/error_management.h"


int check_items(char *result)
{
    if (strcmp(result,"linemate\n") == 0)
        return (1);
    else if (strcmp(result,"deraumere\n") == 0)
        return (2);
    else if (strcmp(result,"sibur\n") == 0)
        return (3);
    else if (strcmp(result,"menidane\n") == 0)
        return (4);
    else if (strcmp(result,"phiras\n") == 0)
        return (5);
    else if (strcmp(result,"thystame\n") == 0)
        return (6);
    else if (strcmp(result,"deraumere\n") == 0)
        return (7);
    else if (strcmp(result,"food\n") == 0)
        return (8);
    return (84);
}

void    add_item_to_client(client_id_t *client, char *item, int option)
{
    printf("add to client:%s:\n", item);
    for (int i = 0; strcmp(client->items[i].name, "end") != 0; i++)
        if (strcmp(strcat(strdup(client->items[i].name), "\n"), item) == 0) {
            printf("enter\n");
            if (option == 1)
                client->items[i].amount++;
            else
                client->items[i].amount--;    
        }
    printf("last\n");
}

void delete_item_in_map(server_t *serv, int y, int x, char *item)
{
    for (int i = 0; strcmp(serv->map[y][x].items[i].name, "end") != 0; i++)
        if (strcmp(strcat(serv->map[y][x].items[i].name, "\n"), item) == 0)
            serv->map[y][x].items[i].amount--;
}

int take(char *result, server_t *serv, client_id_t *clients)
{
    char *ptr = strtok(result, " ");
    char *value = strtok(NULL, " ");
                    


    printf("the ptr:%s, %s\n", ptr, value);
    if (strcmp(ptr, "Take") != 0)
        return (0);
    serv->to_write = strdup("ok\n");
   
    for (int y = 0; serv->map[y] != NULL; y++)
        for (int x = 0; (serv->map[y][x]).is_last == 0; x++)
            for (int i = 0; serv->map[y][x].player != NULL && serv->map[y][x].player[i] != NULL; i++)
                if ((serv->map[y][x]).player[i]->fd == clients->fd) {
                    
                    add_item_to_client(clients, value, 1);
                    delete_item_in_map(serv, y, x, value);
                    //anadir el item a este clients->items
                    //eliminar el item del map->items
                }

    //hacer un bucle por cada elemento del mapa y ver que hay
    return (0);
}
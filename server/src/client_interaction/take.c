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

int take(char *result, server_t *serv, client_id_t *clients)
{
    serv->to_write = strdup("ok\n");
    return (0);
    /* if (check_items(result) == 84){
        printf("Wrong item\n");
    }
    int what_item = check_items(result);
    int dump_x = 0;
    int dump_y = 0;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; (map[y][x]).is_last == 0; x++) {
            for (int i = 0; map[y][x].items->name == result && map[y][x].items->amount > 0; i++){
                dump_x = x;
                dump_y = y;
                pos = get_position(map, clients);
                if (pos.x == dump_x && pos.y == dump_y)
                    take_it(map,clients);
            }
        }
    }*/
}
    //hacer un bucle por cada elemento del mapa y ver que hay
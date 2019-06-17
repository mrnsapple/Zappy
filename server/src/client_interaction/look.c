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

char   *look_up(map_t **map, client_id_t *clients)
{
    return (NULL);
}

char   *look_right(map_t **map, client_id_t *clients)
{
    return (NULL);
}

char   *look_left(map_t **map, client_id_t *clients)
{
    return (NULL);
}

char   *look_down(map_t **map, client_id_t *clients)
{
    return (NULL);
}

int look(char *result, server_t *serv, client_id_t *clients)
{
    printf("in look\n");
    return (0);

    pos_t pos = {-2, -2, -2};
    dir_t dir[] = {
        { 0, look_up },
        { 1, look_left },
        { 2, look_right },
        { 3, look_down },
    };

    if (strcmp(result, "Look\n") != 0)
        return (0);
    return (0);
    for (int i =0; i < 4; i++)
        if (dir[i].dir == clients->direction)
            dir[i].fun_ptr(serv->map, clients);
    pos = get_position(serv->map, clients);
    printf("look asked, %d, %d\n", pos.x, pos.y);
    exit (0);
    return (0);
}

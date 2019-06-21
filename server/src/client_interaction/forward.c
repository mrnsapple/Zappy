/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** forward
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"
#include "../../include/init_server.h"
#include "../../include/server.h"
#include "../../include/map.h"
#include "../../include/error_management.h"

void move_up(int direction, server_t *serv, client_id_t *clients, pos_t pos)
{
    int new_pos_y = pos.y - 1;
    if (new_pos_y < 0)
        new_pos_y = serv->height - 1;
    if (direction == UP) {
        printf("client moved up\n");
        add_to_map(serv, clients, new_pos_y, pos.x);
    }
}

void move_down(int direction, server_t *serv, client_id_t *clients, pos_t pos)
{
    int new_pos_y = pos.y + 1;
    if (new_pos_y > serv->height - 1)
        new_pos_y = 0;
    if (direction == DOWN) {
        printf("client moved down\n");
        add_to_map(serv, clients, new_pos_y, pos.x);
    }
}

void move_left(int direction, server_t *serv, client_id_t *clients, pos_t pos)
{
    int new_pos_x = pos.x - 1;
    if (new_pos_x < 0)
        new_pos_x = serv->width - 1;
    if (direction == LEFT) {
        printf("client moved left\n");
        add_to_map(serv, clients, pos.y, new_pos_x);
    }
}

void move_right(int direction, server_t *serv, client_id_t *clients, pos_t pos)
{
    int new_pos_x = pos.x + 1;
    if (new_pos_x > serv->width - 1)
        new_pos_x = 0;
    if (direction == RIGHT) {
        printf("client moved right\n");
        add_to_map(serv, clients, pos.y, new_pos_x);
    }
}

int forward(char *result, server_t *serv, client_id_t *clients)
{
    if (strcmp(result, "Forward\n") != 0)
        return (0);  
    pos_t pos = get_position(serv->map, clients);
    for (float i = 0; i != (float)(7 / serv->freq); i++);
    if (pos.y != -1 && pos.x != -1 && pos.i != -1) {
        printf("client pos %d,%d is looking %d\n", pos.x, pos.y, clients->direction);        
        serv->map[pos.y][pos.x].player[pos.i] = NULL;
        move_up(clients->direction, serv, clients, pos);
        move_down(clients->direction, serv, clients, pos);
        move_left(clients->direction, serv, clients, pos);
        move_right(clients->direction, serv, clients, pos);
    }
    serv->to_write = "ok";
    return (0);
}
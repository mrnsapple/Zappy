/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <time.h> 
#include "server.h"
pos_t   get_position(map_t ** map, client_id_t *clients);

map_t **init_map(int width, int height);
void display_map(map_t **map);
void fill_map(map_t **map);

typedef struct dir_s {
    int dir;
    char *(*fun_ptr)(map_t **map, client_id_t *clients);
} dir_t;

#endif /* !MAP_H_ */

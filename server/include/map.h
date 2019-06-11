/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "server.h"

//ponlo en una lista o array.
typedef struct item_s{
    char *name;
    int amount;
} item_t;

typedef struct map_s{
    client_id_t *player;
    item_t *gemas;
    int huevo;
} map_t;

#endif /* !MAP_H_ */

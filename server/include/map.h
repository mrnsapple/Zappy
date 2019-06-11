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
typedef struct gems_s{
    char* name;
    int amount;
} gems_t;

typedef struct map_s{
    client_id_t player;
    gems_t gemas;
    int comida;
    int huevo;
} map_t;

#endif /* !MAP_H_ */

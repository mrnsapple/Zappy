/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** create_map
*/

// doble array de estructuras.
// cada casilla del puto mapa es una estructura. 

#include "../include/map.h"

void begin_map(int width, int height)
{
    map_t** map;

    map = malloc(sizeof(map_t) * height);

    for (int y = 0; height != y; y++){
        map[y] = malloc(sizeof(map_t) * width);
    }
}
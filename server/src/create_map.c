/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** create_map
*/

// doble array de estructuras.
// cada casilla del puto mapa es una estructura. 

#include "../include/map.h"

map_t  ***begin_map(int width, int height)
{
    map_t ***map;

    map = malloc(sizeof(map_t) * height);
    map[height] = NULL;
    for (int y = 0; height != y; y++){
        map[y] = malloc(sizeof(map_t) * width);
        map[y][width] = NULL;
    }
    return (map);
}

void check_map(map_t ***map)
{
    for (int i = 0; map[i] != NULL; i++) {
            printf("val\n");
        for (int g = 0; map[i][g] != NULL; g++)
            printf("val\n");
            //en este no entra
    }
}
int main()
{
    map_t ***map;
    
    map = begin_map(20, 20);
    check_map(map);
}
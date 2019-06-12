/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** create_map
*/

#include "../include/map.h"

map_t ***init_map(int width, int height)
{
    map_t ***map;

    map = malloc(sizeof(map_t) * (height * width));
    for (int y = 0; y != height; y++){
        map[y] = malloc(sizeof(map_t*) * height);
        for (int x = 0; x != width; x++) {
            map[y][x] = malloc(sizeof(map_t) * width);
        }
    }
    return (map);
}

void display_map(map_t ***map)
{
    printf("Server map\n");
    for (int i = 0; map[i] != NULL; i++) {
        for (int o = 0; map[i][o] != NULL; o++) {
            // printf("position [%d][%d]\n", i, o);
            printf("x");
        }
        printf("\n");
    }
}

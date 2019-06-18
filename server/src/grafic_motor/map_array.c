/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map_array
*/

#include "../../include/grafic_motor.h"

RectSDL_t **malloc_map(int width, int height)
{
    RectSDL_t **map;

    map = malloc(sizeof(RectSDL_t) * height);
    for (int x = 0; x < height; x++)
        map[x] = malloc(sizeof(RectSDL_t)* (width + 1));
    map[height] = NULL;
    return (map);
}

int is_rect_map_empty(RectSDL_t **rect_map)
{
    int rekt = 0;

    for (int i = 0; rect_map[i] != NULL; i++) {
        if (rect_map[i] == NULL)
            rekt++;
    }
    return (rekt);
}

void init_rect_map(server_t *serv, RectSDL_t ***rect_map)
{
    int i = 0;
    // RectSDL_t **rect_map = malloc_map(serv->width, serv->height);
    // for (int y = 0; serv->map[y] != NULL; y++) {
    //     for (int x = 0; (serv->map[y][x]).is_last == 0; x++) {
    //         rect_map[i] = init_rectangle(init_color(255, 0, 0), init_rect(20 * x, 20 * y, 20, 20));
    //         printf("here %d\n", i);
    //         i++;
    //     }
    // }
    if (is_rect_map_empty((*rect_map)) == 0) {
        for (int y = 0; serv->map[y] != NULL; y++) {
            for (int x = 0; (serv->map[y][x]).is_last == 0; x++) {
                (*rect_map)[i] = init_rectangle(init_color(255, 0, 0), init_rect(15 * (x * 2), 15 * (y * 2), 25, 25));
                // printf("here %d\n", i);
                i++;
            }
        }
        (*rect_map)[i] = NULL;
    }
    // printf("init_rect_map ends here\n");
    // return (*rect_map);
}
/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map_array
*/

#include "../../include/graphic_motor/grafic_motor.h"

rect_sdl_t **malloc_map(int width, int height)
{
    rect_sdl_t **map = {NULL};

    map = malloc(sizeof(rect_sdl_t) * height);
    for (int x = 0; x < height; x++)
        map[x] = malloc(sizeof(rect_sdl_t)* (width + 1));
    map[height] = NULL;
    return (map);
}

void init_rect_map(server_t *serv, rect_sdl_t ***rect_map, rect_sdl_t ***rect_client)
{
    int i = 0;
    int u = 0;

    for (int y = 0; serv->map[y] != NULL; y++) {
        printf("here\n");
        for (int x = 0; serv->map[y][x].is_last == 0; x++) {
            printf("here to me\n");
            (*rect_map)[i] = init_rectangle(REDSDL, MAPRECT(x, y));
            for (int o = 0; serv->map[y][x].player != NULL && serv->map[y][x].player[o] != NULL; o++) {
                printf("here to shall\n");
                (*rect_client)[u] = init_rectangle(CYANSDL, MAPCLIENT(x, y));
                u++;
            }
            i++;
        }
    }
    (*rect_map)[i] = NULL;
    (*rect_client)[u] = NULL;
}

void draw_rect_map(rect_sdl_t **rect_map, SDL_Renderer *render)
{
    for (int o = 0; rect_map[o] != NULL; o++)
        draw_rectangle(rect_map[o], render);
}

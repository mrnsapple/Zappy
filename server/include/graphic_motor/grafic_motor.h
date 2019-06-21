/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** grafic_motor
*/

#ifndef GRAFIC_MOTOR_H_
#define GRAFIC_MOTOR_H_

#include <SDL2/SDL.h>
#include "../server.h"
#include "rect_sdl.h"
#include "color_sdl.h"

typedef struct grafics_s {
    SDL_Window *window;
    SDL_Event event;
    SDL_Renderer *render;
    rect_sdl_t **rect_map;
    rect_sdl_t **rect_client;
} grafics_t;

grafics_t *create_window(server_t *serv);
void window_loop(server_t *serv, grafics_t *graphic);
rect_sdl_t **malloc_map(int width, int height);
void init_rect_map(server_t *serv, rect_sdl_t ***rect_map, rect_sdl_t ***rect_client);
void draw_rect_map(rect_sdl_t **rect_map, SDL_Renderer *render);

#endif /* !GRAFIC_MOTOR_H_ */

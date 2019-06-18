/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** grafic_motor
*/

#ifndef GRAFIC_MOTOR_H_
#define GRAFIC_MOTOR_H_

#include <SDL2/SDL.h>
#include "../include/server.h"
#include "RectSDL.h"

typedef struct grafics_s {
    SDL_Window *window;
    SDL_Event event;
    SDL_Renderer *render;
    RectSDL_t **rect_map;
} grafics_t;

grafics_t *create_window(server_t *serv);
void window_loop(server_t *serv, grafics_t *graphic);
SDL_Color init_color(Uint8 r, Uint8 g, Uint8 b);
SDL_Rect init_rect(int x, int y, int width, int height);
RectSDL_t **malloc_map(int width, int height);
void init_rect_map(server_t *serv, RectSDL_t ***rect_map);

#endif /* !GRAFIC_MOTOR_H_ */

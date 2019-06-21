/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** rect_sdl
*/

#ifndef RECT_SDL_H_
#define RECT_SDL_H_

#include <SDL2/SDL.h>

typedef struct rect_sdl_s {
    SDL_Rect rect;
    SDL_Color color;
} rect_sdl_t;

SDL_Rect init_rect(int x, int y, int width, int height);
rect_sdl_t *init_rectangle(SDL_Color color, SDL_Rect rect);
void draw_rectangle(rect_sdl_t *rekt, SDL_Renderer *render);

#define MAPRECT(x, y) init_rect(25 * (x * 2), 25 * (y * 2), 35, 35)
#define MAPCLIENT(x, y) init_rect(20 * (x * 2), 20 * (y * 2), 20, 20)

#endif /* !RECT_SDL_H_ */

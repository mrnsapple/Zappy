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

#define MAPRECT(x, y) init_rect(15 * (x * 2), 15 * (y * 2), 25, 25)
#define MAPCLIENT(x, y) init_rect(10 * (x * 2), 10 * (y * 2), 10, 10)

#endif /* !RECT_SDL_H_ */

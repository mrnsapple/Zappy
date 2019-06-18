/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** RectSDL
*/

#ifndef RECTSDL_H_
#define RECTSDL_H_

#include <SDL2/SDL.h>

typedef struct RectSDL_s {
    SDL_Rect    rect;
    SDL_Color   color;
}RectSDL_t;

RectSDL_t *init_rectangle(SDL_Color color, SDL_Rect rect);
void draw_rectangle(RectSDL_t *rekt, SDL_Renderer *render);

#endif /* !RECTSDL_H_ */

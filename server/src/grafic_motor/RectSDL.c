/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** RectSDL
*/

#include "../../include/RectSDL.h"

RectSDL_t *init_rectangle(SDL_Color color, SDL_Rect rect)
{
    RectSDL_t *rekt = malloc(sizeof(RectSDL_t));
    rekt->rect = rect;
    rekt->color = color;
    return (rekt);
}

void draw_rectangle(RectSDL_t *rekt, SDL_Renderer *render)
{
    SDL_SetRenderDrawColor(render,rekt->color.r,rekt->color.g,rekt->color.b,rekt->color.a);
    SDL_RenderFillRect(render, &rekt->rect);
}
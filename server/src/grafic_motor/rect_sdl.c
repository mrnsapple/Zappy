/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** rect_sdl
*/

#include "../../include/graphic_motor/rect_sdl.h"

SDL_Rect init_rect(int x, int y, int width, int height)
{
    SDL_Rect rec = {x, y, width, height};
    return (rec);
}

rect_sdl_t *init_rectangle(SDL_Color color, SDL_Rect rect)
{
    rect_sdl_t *rekt = malloc(sizeof(rect_sdl_t));
    rekt->rect = rect;
    rekt->color = color;
    return (rekt);
}

void draw_rectangle(rect_sdl_t *rekt, SDL_Renderer *render)
{
    SDL_SetRenderDrawColor(render,rekt->color.r,rekt->color.g,rekt->color.b,rekt->color.a);
    SDL_RenderFillRect(render, &rekt->rect);
}
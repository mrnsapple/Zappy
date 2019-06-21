/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** color_sdl
*/

#include "../../include/graphic_motor/color_sdl.h"

SDL_Color init_color(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Color color = {r, g, b, 255};
    return (color);
}
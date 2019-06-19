/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** color_sdl
*/

#ifndef COLOR_SDL_H_
#define COLOR_SDL_H_

#include <SDL2/SDL.h>

SDL_Color init_color(Uint8 r, Uint8 g, Uint8 b);

#define WHITESDL init_color(255, 255, 255)
#define REDSDL init_color(255, 0, 0)
#define GREENSDL init_color(0, 255, 0)
#define BLUESDL init_color(0, 0, 255)
#define CYANSDL init_color(0, 255, 255)
#define BLACKSDL init_color(0, 0, 0)

#endif /* !COLOR_SDL_H_ */

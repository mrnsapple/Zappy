/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** triangle_sdl
*/

#include "../../include/triangle_sdl.h"

void draw_triangle(SDL_Renderer *render)
{
	SDL_SetRenderDrawColor(render, 0, 255, 255, 0);

	//Drawing the lines we want. (-1, 0), (0, 1), (1, 0)
    // SDL_RenderDrawLine(render, 0, 48 / 2, 32 / 2, 0);
	// SDL_RenderDrawLine(render, 64 / 2, 48 / 2, 32 / 2, 0);
	// SDL_RenderDrawLine(render, 0, 48 / 2, 64 / 2, 48 / 2);

    // SDL_RenderDrawLine(render, 320, 200, 300, 240);
    // SDL_RenderDrawLine(render, 300, 240, 340, 240);
    // SDL_RenderDrawLine(render, 340, 240, 320, 200);
    SDL_RenderDrawLine(render, 12 * 4, 0, 10 * 4, 4 * 4);
    SDL_RenderDrawLine(render, 10 * 4, 4 * 4, 14 * 4, 4 * 4);
    SDL_RenderDrawLine(render, 14 * 4, 4 * 4, 12 * 4, 0);
}
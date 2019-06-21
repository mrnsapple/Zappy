/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map_grafic. Needs to be done with SDL. Good luck
*/

#include "../../include/server.h"
#include "../../include/graphic_motor/grafic_motor.h"

grafics_t *create_window(server_t *serv)
{
    grafics_t *grafics;
    grafics = malloc(sizeof(grafics_t));
    SDL_Init(SDL_INIT_VIDEO);
    grafics->window = SDL_CreateWindow(
        "Zappy",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    if (grafics->window == NULL) {
        printf("Could not create window: %s \n", SDL_GetError()); 
        exit(84);
    }
    grafics->render = SDL_CreateRenderer(grafics->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    grafics->rect_map = malloc_map(serv->width, serv->height);
    grafics->rect_client = malloc_map(serv->width, serv->height);
    return (grafics);
}

void window_loop(server_t *serv, grafics_t *graphic)
{
    SDL_SetRenderDrawColor(graphic->render, 0, 0, 0, 0);
    SDL_RenderClear(graphic->render);
    while ( SDL_PollEvent(&graphic->event) != 0){
        if (graphic->event.type == SDL_QUIT) {
            serv->_stop_server = 0;
        }
    }
    init_rect_map(serv, &graphic->rect_map, &graphic->rect_client);
    draw_rect_map(graphic->rect_map, graphic->render);
    if (graphic->rect_map != NULL) {
        draw_rect_map(graphic->rect_client, graphic->render);
    }
    // draw_triangle(graphic->render);
    // SDL_RenderPresent(graphic->render);
}
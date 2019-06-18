/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map_grafic. Needs to be done with SDL. Good luck
*/

#include "../../include/server.h"
#include "../../include/grafic_motor.h"

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
    return (grafics);
}

SDL_Color init_color(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Color color = {r, g, b, 255};
    return (color);
}

SDL_Rect init_rect(int x, int y, int width, int height)
{
    SDL_Rect rec = { x, y, width, height};
    return (rec);
}

void window_loop(server_t *serv, grafics_t *graphic)
{
    // int i = 0;
    SDL_SetRenderDrawColor(graphic->render, 0, 0, 0, 0);
    SDL_RenderClear(graphic->render);
    // graphic->rect_map = malloc_map(serv->width, serv->height);
    while ( SDL_PollEvent(&graphic->event) != 0){
        if (graphic->event.type == SDL_QUIT) {
            serv->_stop_server = 0;
        }
    }
    init_rect_map(serv, &graphic->rect_map);
    for (int o = 0; graphic->rect_map[o] != NULL; o++) {
        // printf("here o is %d\n", o);
        draw_rectangle(graphic->rect_map[o], graphic->render);
    }
    // RectSDL_t *rectangulo = init_rectangle(init_color(255, 0, 0), init_rect(50, 50, 20, 20));
    // draw_rectangle(rectangulo, graphic->render);
    SDL_RenderPresent(graphic->render);
}
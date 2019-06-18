/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map_grafic. Needs to be done with SDL. Good luck
*/

#include "../../include/server.h"
#include "../../include/grafic_motor.h"

grafics_t *create_window(void)
{
    grafics_t *grafics;
    grafics = malloc(sizeof(grafics_t));
    SDL_Init (SDL_INIT_VIDEO);
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
    printf("window should be made here or something\n");
    return (grafics);
}

void window_loop(server_t *serv, grafics_t *graphic)
{
    SDL_SetRenderDrawColor(graphic->render, 0, 0, 0, 0);
    SDL_RenderClear(graphic->render);
    //The window is opened: could enter program loop here.
    while ( SDL_PollEvent(&graphic->event) != 0){
        if (graphic->event.type == SDL_QUIT) {
            serv->_stop_server = 0;
        }
    }
    SDL_Color color = {255, 0, 0, 0};
    SDL_Rect rec = { 50, 50, 20, 20};
    RectSDL_t *rectangulo = init_rectangle(color, rec);
    draw_rectangle(rectangulo, graphic->render);
    SDL_RenderPresent(graphic->render);
    // SDL_UpdateWindowSurface(graphic->window);
}

// void display_map (map_t **map)
// {
//     create_window();
// }

// //Dump main for testing 
// int main ()
// {
//     create_window();
//     exit(0);
// }
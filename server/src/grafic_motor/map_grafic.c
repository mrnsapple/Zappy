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
        SDL_WINDOW_OPENGL
    );
    if (grafics->window == NULL) {
        printf("Could not create window: %s \n", SDL_GetError()); 
        exit(84);
    }
    printf("window should be made here or something\n");
    return (grafics);
}

void window_loop(server_t *serv, grafics_t *graphic)
{
    //The window is opened: could enter program loop here.
    // grafics_t *grafics;
    // grafics = malloc(sizeof(grafics));
    
    while ( SDL_PollEvent(&graphic->event) != 0){
        if (graphic->event.type == SDL_QUIT) {
            printf("i'm here\n");
            serv->_stop_server = 0;
        }
    }

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
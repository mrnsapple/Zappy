/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** grafic_motor
*/

#ifndef GRAFIC_MOTOR_H_
#define GRAFIC_MOTOR_H_

#include "SDL2/SDL.h"


typedef struct grafics_s {
    SDL_Window *window;
    SDL_Event event;
    SDL_Surface *imageSurface;
    SDL_Surface *windowSurface;
} grafics_t;
grafics_t *create_window(void);
void window_loop(server_t *serv, grafics_t *graphic);


#endif /* !GRAFIC_MOTOR_H_ */

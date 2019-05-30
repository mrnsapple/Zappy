/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** get_arguments
*/

#include "../include/get_arguments.h"

server_t *take_arguments(int ac, char **av)
{
    server_t    *server = malloc(sizeof(server_t));

    for (int i = 1; i != ac; i++) {
        if (strcmp(av[i], "-p") == 0)
            server->port = atoi(av[i + 1]);
        if (strcmp(av[i], "-x") == 0)
            server->width = atoi(av[i + 1]);
        if (strcmp(av[i], "-y") == 0)
            server->height = atoi(av[i + 1]);
        if (strcmp(av[i], "-n") == 0) {
            int old = i;
            server->team_names = malloc(sizeof(char*) * 10);
            for (int o = 0; strcmp(av[i + 1], "-c") != 0; o++, i++) {
                server->team_names[o] = av[i + 1];
            }
            i = old;
        }
        if (strcmp(av[i], "-c") == 0)
            server->client_nb = atoi(av[i + 1]);
        if (strcmp(av[i], "-f") == 0)
            server->freq = atoi(av[i + 1]);
        // printf("%d -> %d -> %s\n", i, ac, av[i]);
    }
    return (server);
}
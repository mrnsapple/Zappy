/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** get_arguments
*/

#include "../include/get_arguments.h"

int is_number_negative(int num)
{
    if (num <= 0)
        exit(84);
    return (num);
}

int size_limit(int num)
{
    if (num > 100)
        exit(84);
    return num;
}

void get_team_names(server_t **serv, int i, char **av)
{
    int old = i;
    (*serv)->team_names = malloc(sizeof(char*) * 10);
    for (int o = 0; strcmp(av[i + 1], "-c") != 0; o++, i++)
        (*serv)->team_names[o] = av[i + 1];
    i = old;
}

void get_size(server_t **serv, char **av, int i)
{
    if (strcmp(av[i], "-x") == 0)
        (*serv)->width = size_limit(is_number_negative(atoi(av[i + 1])));
    if (strcmp(av[i], "-y") == 0)
        (*serv)->height = size_limit(is_number_negative(atoi(av[i + 1])));
}

server_t *take_arguments(int ac, char **av)
{
    server_t    *server = malloc(sizeof(server_t));

    for (int i = 1; i != ac; i++) {
        if (strcmp(av[i], "-p") == 0)
            server->port = is_number_negative(atoi(av[i + 1]));
        get_size(&server, av, i);
        if (strcmp(av[i], "-n") == 0)
            get_team_names(&server, i, av);
        else if (strcmp(av[i], "-c") == 0)
            server->client_nb = is_number_negative(atoi(av[i + 1]));
        if (strcmp(av[i], "-f") == 0)
            server->freq = is_number_negative(atoi(av[i + 1]));
        // printf("%d -> %d -> %s\n", i, ac, av[i]);
    }
    return (server);
}
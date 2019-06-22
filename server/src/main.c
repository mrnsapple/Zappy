/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** main
*/

#include "../include/error_management.h"
#include "../include/server.h"
#include "../include/get_arguments.h"
#include "../include/init_server.h"
#include "../include/map.h"
#include <signal.h>


int server(int ac, char **av)
{
    int val = check_arg(ac, av[1]);
    server_t *server;
    int res = 0;

    if (val == 1)
        return (print_help());
    else if (val == -1)
        return (84);
    server = take_arguments(ac, av);
    server->map = init_map(server->width, server->height);
    server->sock = init_server(server);
    if (server->sock == NULL)
        return (84);
    res = init_listen(server->sock->fd, server->client_nb, server->team_names);
    if (res == -1)
        return (84);
    return (start_server(server));
}

int main(int ac, char **av)
{
    srand(time(0));
    return (server(ac, av));
}

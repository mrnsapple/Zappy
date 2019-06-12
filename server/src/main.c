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

int server(int ac, char **av)
{
    int val = check_arg(ac, av[1]);
    server_t *server;

    if (val == 1)
        return (print_help());
    else if (val == -1)
        return (84);
    server = take_arguments(ac, av);
    server->map = init_map(server->width, server->height);
    display_map(server->map);
    server->sock = init_server(server);
    init_listen(server->sock->fd, server->client_nb, server->team_names);
    FD_ZERO(&server->sock->fds);
    FD_SET(server->sock->fd, &server->sock->fds);
    start_server(server);
    return (0);
}

int main(int ac, char **av)
{
    return (server(ac, av));
}

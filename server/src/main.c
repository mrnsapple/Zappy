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

int main(int ac, char **av)
{
    int val = check_arg(ac, av[1]);
    server_t *server;

    if (val == 1)
        print_help();
    else if (val == 0) {
        server = take_arguments(ac, av);
        server->sock = init_server(server);
        init_listen(server->sock->fd);
        FD_ZERO(&server->sock->fds);
        FD_SET(server->sock->fd, &server->sock->fds);
        start_server(server);
    }
    else
        return (84);
    return (0);
}
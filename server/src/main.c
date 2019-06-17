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

void stopServer(int signal)
{
    if (signal == SIGINT) {
        perror("Server interrumped\n");
        exit (84);
    }
}

int server(int ac, char **av)
{
    int val = check_arg(ac, av[1]);
    server_t *server;

    if (val == 1)
        return (print_help());
    else if (val == -1)
        return (84);
    server = take_arguments(ac, av);
    //signal(SIGINT, stopServer);
    server->map = init_map(server->width, server->height);
    printf("afterinitmap\n");
    server->sock = init_server(server);
    init_listen(server->sock->fd, server->client_nb, server->team_names);
    
    start_server(server);
    return (0);
}

int main(int ac, char **av)
{
    srand(time(0));
    return (server(ac, av));
}

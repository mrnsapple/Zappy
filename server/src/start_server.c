/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** start_server
*/

#include "../include/init_server.h"
#include "../include/server.h"
#include "../include/error_management.h"
#include "../include/client_management.h"
#include "../include/map.h"
#include "../include/graphic_motor/grafic_motor.h"

char *remove_char(char *str, char x)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == x)
            str[i] = '\0';
    return (str);
}

char *remove_spaces(char *str)
{
    for (int i = 0; str && str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
    return (str);
}

char *get_team_name(char **team_names, int client_fd)
{
    //printf("new connection %s:%d\n", inet_ntoa(serv->sock->dest.sin_addr), ntohs(serv->sock->dest.sin_port));
    char *team_name;

    write_to_fd(client_fd, "WELCOME\n");
    team_name = remove_spaces(read_user(client_fd));
    for (int i = 0; team_names != NULL && team_names[i] != NULL; i++)
        if (strcmp(team_names[i], team_name) == 0)
            return (team_name);
    write_to_fd(client_fd, "ko\n");
    return (NULL);
    
}

void fd_stuff(server_t *serv)
{
    teams_t *teams = serv->sock->teams;
    client_id_t *clients;

    FD_ZERO(&(serv->sock->readFds));
    FD_SET(serv->sock->fd, &(serv->sock->readFds));
    for (; teams != NULL; teams = teams->next) {
        clients = teams->clients;
        for (; clients != NULL; clients = clients->next) {
            // printf("client fd:%d\n", clients->fd);
            if (clients->is_dead == 0)
                FD_SET (clients->fd, &(serv->sock->readFds));
        }
    }
}

void get_connections(server_t *serv)
{
    int fd;
    char *team_name;

    for (int i = 0; i < FD_SETSIZE; i++)
        if (FD_ISSET(i, &serv->sock->readFds)) {
            if (i == serv->sock->fd) {
                // printf("Awaiting for a new connection\n");
                fd = init_accept(serv);
                printf("Connection with fd %d has been accepted\n", fd);
                team_name = get_team_name(serv->team_names, fd);
                init_client(serv, fd, team_name);
                // printf("afterinitclient\n");
            }
            //else
            //    delete_client(serv, i);
            //    client_interaction(serv, i);
        }
}

void start_server(server_t *serv)
{
    serv->_stop_server = 1;
    // grafics_t *graphic = create_window(serv);
    while (serv->_stop_server == 1) {
        SDL_Delay(1000);
        // window_loop(serv, graphic);
        // display_map(serv->map);
        fd_stuff(serv);
        init_select(&(serv->sock->readFds));
        get_connections(serv);
        client_interaction(serv);
        // SDL_RenderPresent(graphic->render);
    }
    printf("Loop ended\n");
    close(serv->sock->fd);
}
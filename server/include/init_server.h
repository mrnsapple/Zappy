/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** init_server
*/

#ifndef INIT_SERVER_H_
#define INIT_SERVER_H_

#include "../include/server.h"

void init_listen(int fd, int client_nb, char **teams_nb);
void init_select(fd_set *fds);
int init_accept(server_t *serv);
socket_t *init_server(server_t *serv);
void start_server(server_t *serv);
void display_map(map_t **map);

#endif /* !INIT_SERVER_H_ */

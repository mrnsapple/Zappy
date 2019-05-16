/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include "essentials.h"

typedef struct socket_s {
    int fd;
    int client;
    struct sockaddr_in address;
    struct sockaddr_in dest;
    fd_set fds;
    fd_set readFds;
} socket_t;

typedef struct server_s {
    int port;
    int width;
    int height;
    char **team_names;
    int client_nb;
    int freq;
    pid_t pid;
    socket_t *sock;
} server_t;

#endif /* !SERVER_H_ */

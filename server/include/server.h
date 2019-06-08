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

typedef struct object_s {
    char *name;
    int num;
} object_t;

typedef struct client_inventory_s {
    object_t linemate;
    object_t deraumere;
    object_t sibur;
    object_t mendiane;
    object_t phiras;
    object_t thystame;
    object_t food;
} client_inventory_t;

typedef struct client_id_s {
    //the file descriptor 
    int fd;
    //the team name
    char *name;

    struct client_id_s *next;
} client_id_t;


typedef struct teams_s {
    //the file descriptor 
    int clients_in_team;
    //the team name
    char *name;
    client_id_t *clients;
    struct team_s *next;

} teams_t;

typedef struct socket_s {
    int fd;
    teams_t *teams;
    //int client;
    struct sockaddr_in address;
    struct sockaddr_in dest;
    fd_set fds;
    fd_set readFds;
} socket_t;

typedef struct server_s {
    int port;
    int width;
    int height;
    int client_nb;
    int freq;
    pid_t pid;
    socket_t *sock;
} server_t;

#endif /* !SERVER_H_ */

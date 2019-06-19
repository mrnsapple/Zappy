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

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

typedef struct item_s {
    char *name;
    int amount;
} item_t;

typedef struct pos_s {
    int x;
    int y;
    int i;
} pos_t;

typedef struct client_id_s {
    //the file descriptor
    int fd;
    //know if map size has been sent
    int send_map_size;
    //the team name
    char *team_name;
    item_t *items;
    int direction;
    struct client_id_s *next;
    int is_dead;
} client_id_t;


typedef struct teams_s {
    //the file descriptor
    int clients_in_team;
    //the team name
    char *team_name;
    client_id_t *clients;
    struct teams_s *next;
} teams_t;

typedef struct socket_s {
    int fd;
    teams_t *teams;
    //int client;
    struct sockaddr_in address;
    struct sockaddr_in dest;
    // fd_set fds;
    int max_sd;
    int sd;
    fd_set readFds;
} socket_t;

typedef struct map_s {
    client_id_t **player;
    item_t *items;
    int is_last;
    int egg;
} map_t;

typedef struct server_s {
    int port;
    int width;
    int height;
    int client_nb;
    char **team_names;
    int freq;
    pid_t pid;
    socket_t *sock;
    map_t **map;
    //bool for know when stop server
    int _stop_server;
    //To_write
    char *to_write;
} server_t;

#endif /* !SERVER_H_ */

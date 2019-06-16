/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** init_server
*/

#include "../include/init_server.h"

void init_listen(int fd, int client_nb, char **team_names)
{
    //Numero de equipos * numero de clientes por equipo
    //numero maximo de jugadores
    int teams = 0;
    for (int i = 0;team_names[i] != NULL; i++) 
        teams++;
    int max_number = teams * client_nb;
    if (listen(fd, max_number) < 0) {
        perror("Listening failed");
        exit(84);
    }
}

int init_socket(void)
{
    int sockfd;
    int sockopt;
    int nm = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(84);
    }
    sockopt = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &nm, sizeof(nm));
    if (sockopt < 0) {
        perror("Socket options failed");
        exit(0);
    }
    return (sockfd);
}

struct sockaddr_in init_bind_address(int port, int fd)
{
    struct sockaddr_in address;
    int bindRes;

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;
    bindRes = bind(fd, (struct sockaddr*)&address, sizeof(address));
    if (bindRes == -1) {
        perror("socket binding failed");
        exit(84);
    }
    return (address);
}

void init_select(fd_set *readFds)
{   
    struct timeval time = {.tv_sec = 0.000000001, .tv_usec = 1}; 
    //if (select(FD_SETSIZE, &readFds, NULL, NULL, &time) < 0) {
    // struct timeval time = {.tv_sec = 1, .tv_usec = 1}; 
    if (select(FD_SETSIZE, readFds, NULL, 0,  &time) < 0) {
        perror("Select failed");
        exit(84);
    }
}

int init_accept(server_t *serv)
{
    int addrlen = sizeof(serv->sock->dest);
    int sock;

    sock = accept(serv->sock->fd, (struct sockaddr*)&serv->sock->address, (socklen_t*)&addrlen);
    if (sock < 0) {
        perror("accepting failed");
        exit(84);
    }
    return (sock);
}

socket_t *init_server(server_t *serv)
{
    socket_t *sock = malloc(sizeof(socket_t));

    if (sock == NULL)
        return (NULL);
    sock->teams = NULL;
    sock->fd = init_socket();
    sock->address = init_bind_address(serv->port, sock->fd);
    return (sock);
}
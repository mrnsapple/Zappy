/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** error_management
*/

#include "../include/essentials.h"
#include "../include/client_management.h"

client_id_t *malloc_client(int fd)
{
    client_id_t *client;

    client = malloc(sizeof(client_id_t));
    if (client == NULL)
        exit (84);
    client->next = NULL;
    client->fd = fd;
    return client;
}/*

int    init_client(socket_t *socket, int fd)
{
    client_id_t *clients = socket->clients;

    if (socket->clients == NULL)
        socket->clients = malloc_client(fd);
    else {
        for (clients = clients; clients->next != NULL; clients = clients->next);
        clients->next = malloc_client(fd);
    }
    return (0); 
}

void    client_interaction(server_t *serv)
{
    client_id_t *clients = serv->sock->clients;
    
    for (; clients != NULL; clients = clients->next)
        printf("the fd:%d\n", clients->fd );
}
*/
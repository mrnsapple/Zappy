/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** error_management
*/

#include "../include/essentials.h"
#include "../include/client_management.h"

client_id_t *malloc_client(int fd, char *team_name)
{
    client_id_t *client;

    client = malloc(sizeof(client_id_t));
    if (client == NULL)
        exit(84);
    client->next = NULL;
    client->fd = fd;
    client->team_name = team_name;
    return client;
}

teams_t *malloc_team(client_id_t *client)
{
    teams_t *team;
    
    team = malloc(sizeof(teams_t));
    if (team == NULL)
        exit(84);
    team->clients = client;
    team->team_name = client->team_name;
    team->clients_in_team = 1;
    return team;
}

int add_client_to_existing_team(int client_nb, teams_t *team, client_id_t *client)
{
    client_id_t *clients = team->clients;

    if (team->clients_in_team > client_nb) {
        write_to_fd(client->fd, "ko\n");
        return (-1);
    }
    for (clients = clients; clients->next != NULL; clients = clients->next);
        clients->next = client;
    return (0);
}

int    init_client(server_t *serv, int fd, char *team_name)
{
    teams_t *teams = serv->sock->teams;

    if (serv->sock->teams == NULL)
        serv->sock->teams = malloc_team(malloc_client(fd, team_name));
    
    else {
        //check team already exists
        for (teams = teams; teams != NULL; teams = teams->next)
            if (strcmp(teams->team_name, team_name) == 0)
                add_client_to_existing_team(serv->client_nb, teams, malloc_client(fd, team_name));
        for (teams = teams; teams->next != NULL; teams = teams->next);
            teams->next = malloc_team(malloc_client(fd, team_name));
    }
    return (0); 
}
/*
void    client_interaction(server_t *serv)
{
    client_id_t *clients = serv->sock->clients;
    
    for (; clients != NULL; clients = clients->next)
        printf("the fd:%d\n", clients->fd );
}
*/
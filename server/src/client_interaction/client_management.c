/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** error_management
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"
#include "../../include/init_server.h"
#include "../../include/server.h"
#include "../../include/error_management.h"

void add_to_map(server_t *serv, client_id_t *client)
{
    int pos_x = rand() % serv->width;
    int pos_y = rand() % serv->height;
    printf("x:%d,y:%d\n", pos_x, pos_y);
    serv->map[pos_x][pos_y].player = &client;
    
    for (int y = 0; serv->map[y] != NULL; y++) {
        for (int x = 0; (serv->map[y][x]).is_last == 0; x++) {
            if (serv->map[y][x].player == NULL)
                printf("x");
            else
                printf("o");
            //display_items(map[y][x].items);
        }
        printf("\n");
    }
}

client_id_t *malloc_client(int fd, char *team_name, server_t *serv)
{
    client_id_t *client;
    item_t items[] = {
        { .name = "food", .amount = 10 },
        { .name = "linemate", .amount = 0 },
        { .name = "deraumere", .amount = 0 },
        { .name = "sibur", .amount = 0 },
        { .name = "mendiane", .amount = 0 },
        { .name = "phiras", .amount = 0 },
        { .name = "thystame", .amount = 0 },
        { .name = "end", .amount = 0 },

    };

    client = malloc(sizeof(client_id_t));
    if (client == NULL)
        exit(84);
    client->next = NULL;
    client->fd = fd;
    client->team_name = team_name;
    client->send_map_size = 1;
    client->items = malloc(sizeof(client_id_t) * 9);
    //buff = malloc(totalsize);
    memcpy(client->items, &items, sizeof(item_t) * 9);
    add_to_map(serv, client);
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

    if (team->clients_in_team >= client_nb) {
        perror("Can not add another client in team\n");
        write_to_fd(client->fd, "ko\n");
        return (-1);
    }
    for (clients = clients; clients->next != NULL; clients = clients->next);
    clients->next = client;
    team->clients_in_team += 1;
    return (0);
}

int    init_client(server_t *serv, int fd, char *team_name)
{
    teams_t *teams = serv->sock->teams;

    if (serv->sock->teams == NULL)
        serv->sock->teams = malloc_team(malloc_client(fd, team_name, serv));
    else {
        //check team already exists
        for (teams = teams; teams != NULL; teams = teams->next)
            if (strcmp(teams->team_name, team_name) == 0)
                return (add_client_to_existing_team(serv->client_nb, teams, malloc_client(fd, team_name, serv)));
        //create team
        teams = serv->sock->teams;
        for (teams = teams; teams->next != NULL; teams = teams->next);
        teams->next = malloc_team(malloc_client(fd, team_name, serv));
    }
    return (0);
}

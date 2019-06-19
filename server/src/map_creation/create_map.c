/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** create_map
*/

#include "../../include/map.h"
#include <time.h> 

void display_items(item_t *items)
{
    for (int i = 0; strcmp(items[i].name, "end") != 0; i++)
        printf(",%s:%d,", (items[i]).name, (items[i]).amount);
    printf("\n");
}

void display_players(client_id_t **players)
{
    printf("players:");
    for (int i = 0; players != NULL && players[i] != NULL; i++)
        printf("%s, %d", players[i]->team_name, players[i]->fd);
    //printf("\n");
}

map_t **init_map(int width, int height)
{
    map_t **map;

    map = malloc(sizeof(map_t*) * height);
    for (int x = 0; x < height; x++)
        map[x] = malloc(sizeof(map_t) * (width + 1));
    map[height] = NULL;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; x < width; x++) {
            (map[y][x]).is_last = 0;
            map[y][x].player = NULL;
        }
        map[y][width].is_last = 1;
    }
    fill_map(map);
    return (map);
}

item_t *copy_of_items(void)
{
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
    int i = 0;
    item_t *c_items = NULL;

    for (i = 0; strcmp(items[i].name, "end") != 0; i++);
    c_items = malloc(sizeof(item_t *) * (i + 20));
    for (i = 0; strcmp(items[i].name, "end") != 0; i++) {
        c_items[i].name = strdup(items[i].name);
        c_items[i].amount = items[i].amount;
    }
    c_items[i].name = strdup(items[i].name);
    c_items[i].amount = items[i].amount;
    return (c_items);
}

item_t    *randomize_items(void)
{
    item_t *items = copy_of_items(); 
    for (int i = 0; strcmp(items[i].name, "end") != 0; i++) {
        items[i].amount = rand() % 6;
    }
    return (items);
}

void    fill_map(map_t **map)
{
    for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; (map[y][x]).is_last == 0; x++)
            map[y][x].items = randomize_items();
}

void display_map(map_t **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; (map[y][x]).is_last == 0; x++) {
            display_players(map[y][x].player);
            display_items(map[y][x].items);
        }
    }
    
    printf("\n\n");

}

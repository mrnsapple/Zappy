/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** create_map
*/

#include "../../include/map.h"
#include<time.h> 

void display_items(item_t *items)
{
    for (int i = 0; strcmp(items[i].name, "end") != 0; i++)
        printf("d:%s:%d,", (items[i]).name, (items[i]).amount);
    printf("\n");
}

map_t **init_map(int width, int height)
{
    map_t **map;

    map = malloc(sizeof(map_t*) * height);
    for (int x = 0; x < height; x++)
        map[x] = malloc(sizeof(map_t) * (width + 1));
    map[height] = NULL;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; x < width; x++)
            (map[y][x]).is_last = 0;
        map[y][width].is_last = 1;
    }
    fill_map(map);
    return (map);
}

item_t    *randomize_items(item_t *items)
{
    
    for (int i = 0; strcmp(items[i].name, "end") != 0; i++) {
        items[i].amount = rand() % 5;
        printf("randval:%d\n", items[i].amount);
    }
    //printf("before mempcy\n");
    return (items);
}

void    fill_map(map_t **map)
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
    srand(time(0));
    for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; (map[y][x]).is_last == 0; x++) {
            map[y][x].items = items;
            map[y][x].items = randomize_items(map[y][x].items);

        }
      for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; (map[y][x]).is_last == 0; x++)
            display_items(map[y][x].items);
    
}

void display_map(map_t **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; (map[y][x]).is_last == 0; x++) {
            printf("x");
            //display_items(map[y][x].items);
        }
        printf("\n");
    }

}

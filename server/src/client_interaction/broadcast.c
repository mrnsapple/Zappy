/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** broadcast
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"
#include "../../include/init_server.h"
#include "../../include/server.h"
#include "../../include/map.h"
#include "../../include/error_management.h"

char *substring(char *str, int pos, int len)
{
    char *substr = malloc(sizeof(char) * len + 1);
    int i;

    for (i = 0; i < len; i++) {
        *(substr + i) = *(str + pos - 1);
        str++;
    }
    *(substr + i) = '\0';
    return (substr);
}

int find_space(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            break;
    }
    return (i);
}

int broadcast(char *result, server_t *serv, client_id_t *clients)
{
    char *res = substring(result, 0, find_space(result));
    char *text = substring(result, find_space(result), strlen(result));

    if (strcmp(res, "Broadcast") != 0)
        return (0);
    return (0);
}
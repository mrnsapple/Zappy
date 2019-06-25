/*
** EPITECH PROJECT, 2019
** client interaction
** File description:
** client_interaction
*/

#include "../../include/essentials.h"
#include "../../include/client_management.h"
#include "../../include/init_server.h"
#include "../../include/server.h"
#include "../../include/map.h"
#include "../../include/error_management.h"

int look(char *result, server_t *serv)
{
    if (strcmp(result, "Look\n") != 0)
        return (0);
    for (float i = 0; i != (float)(7 / serv->freq); i++);
    serv->to_write = "[ player food sibur, phiras,, food sibur ]\n";

    return (0);
}

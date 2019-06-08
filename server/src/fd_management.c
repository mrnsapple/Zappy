/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** start_server
*/

#include "../include/init_server.h"
#include "../include/client_management.h"

#include "../include/server.h"

char *read_user(int fd)
{
    char buff[1024];
    char *str;

    bzero(buff, 1024);
    if (read(fd, buff, 1024) < 0)
        return (NULL);
    str = strdup(buff);
    return (str);
}

int write_to_fd(int fd, char *str)
{
    if (write(fd, str, strlen(str)) == -1)
        exit(84);
    return (0);
}
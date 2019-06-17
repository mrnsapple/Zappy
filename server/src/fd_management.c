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
    int result;

    bzero(buff, 1024);
    result = read(fd, buff, 1024);
    if (result < 0) {
        perror("Read error\n");
        return (NULL);
    }
    else if (result == 0)
        return (strdup("DELETE CLIENT"));
    str = strdup(buff);
    return (str);
}

int write_to_fd(int fd, char *str)
{
    if (write(fd, str, strlen(str)) == -1) {
        perror("write fail\n");
        exit(84);
    }
    printf("writen_to_fd:%s\n", str);
    return (0);
}
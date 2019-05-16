/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** main
*/

#include "../include/essentials.h"
#include "../include/error_management.h"

int main(int ac, char **av)
{
    if (ac == 2)
        if (strcmp(av[1], "-help") == 0)
            print_help();
    return (0);
}
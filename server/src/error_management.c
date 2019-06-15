/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** error_management
*/

#include "../include/essentials.h"

int print_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height");
    printf(" -n name1 name2 ... -c clientNb -f freg\n");
    printf("\tport\tis the port number\n");
    printf("\twidth\tis the width of the world\n");
    printf("\theight\tis the height of the world\n");
    printf("\tnameX\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\tis the reciprocal of time");
    printf(" unit for execution of actions\n");
    return (0);
}

int check_arg(int ac, char *first_arg)
{
    if (ac == 2 && strcmp(first_arg, "--help") == 0)
        return (1);
    else if (ac > 12)
        return (0);
    return (-1);
}
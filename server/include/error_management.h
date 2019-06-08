/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** error_management
*/

#ifndef ERROR_MANAGEMENT_H_
#define ERROR_MANAGEMENT_H_

int print_help(void);
int check_arg(int ac, char *first_arg);
char *read_user(int fd);
char *write_to_fd(int fd, char *str);

#endif /* !ERROR_MANAGEMENT_H_ */

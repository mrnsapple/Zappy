/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** start_server
*/

#include "../include/init_server.h"
#include "../include/server.h"
#include "../include/error_management.h"

char *remove_char(char *str, char x)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == x)
            str[i] = '\0';
    return (str);
}
/*
int check_name(server_t *serv, char *clientName)
{
    clientName = remove_char(clientName, '\n');
    for (int i = 0; serv->team_names != NULL; i++)
        if (strcmp(serv->team_names[i], clientName))
            return (1);
    return (0);
}*/

void user_interaction(int client_fd)
{
    //printf("new connection %s:%d\n", inet_ntoa(serv->sock->dest.sin_addr), ntohs(serv->sock->dest.sin_port));
    char *team_name;

    write_to_fd(client_fd, "WELCOME\n");
    team_name = read_user(client_fd);
    /*if (check_name(serv, read_user(serv->sock->client)) == 1) {
        char str[10];
        sprintf(str, "%d\n%d %d\n", serv->client_nb, serv->width, serv->height);
        write(serv->sock->client, str, sizeof(str));
        serv->client_nb -= 1;
    } else {
        write(serv->sock->client, "ko\n", 4);
    }*/
}

void get_connections(server_t *serv)
{
    int fd;
    char *team_name;

    for (int i = 0; i < FD_SETSIZE; i++)
        if (FD_ISSET(i, &serv->sock->readFds))
            if (i == serv->sock->fd) {
                fd = init_accept(serv);
                team_name = get_team_name(fd);

                init_client(serv->sock, init_accept(serv));
                client_interaction(serv);
                //serv->sock->client = init_accept(serv);
                //serv->pid = fork();
               //user_interaction(serv);
            }
}

void start_server(server_t *serv)
{
    while (1) {
        serv->sock->readFds = serv->sock->fds;
        init_select(serv->sock->readFds);
        get_connections(serv);
    }
    close(serv->sock->fd);
}
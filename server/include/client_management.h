/*
** EPITECH PROJECT, 2019
** client mangement
** File description:
** client_man
*/

#ifndef clientman
#define clientman
#include "essentials.h"
#include "server.h"


int    init_client(socket_t *socket, int fd);
void    client_interaction(server_t *serv);


#endif /* !clientman */

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


int    init_client(server_t *serv, int fd, char *team_name);
void    client_interaction(server_t *serv);


#endif /* !clientman */

/*
** EPITECH PROJECT, 2019
** Client
** File description:
** Info about client
*/

# include "Interact.hpp"
# ifndef MyClient
# define MyClient
# include "../include/list.hpp"
# include "player/Player.hpp"


class Client {
public:
        Client();
        ~Client();
        void    setName(std::string);
        void    setPort(int);
        void    setMachine(std::string);
        int     createPlayer();
protected:
private:
        int _port;
        std::string _name;
        std::string _machine;
        std::vector<Player*> _players;
};

#endif /* !d */

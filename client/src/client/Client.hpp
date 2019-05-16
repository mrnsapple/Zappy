/*
** EPITECH PROJECT, 2019
** Client
** File description:
** Info about client
*/

# ifndef MyClient
# define MyClient
# include "../../include/list.hpp"
# include "../player/Player.hpp"


class Client {
public:
        Client();
        ~Client();
        void    setName(std::string);
        void    setPort(int);
        void    setMachine(std::string);
        int     createPlayer();
        int     startClient();
        std::string     createFifo(std::string );

protected:
private:
        int _port;
        std::string _name;
        std::string _machine;
        std::vector<Player*> _players;

        // Communicate client player
        std::string     _fifo_read;
        
};

#endif /* !d */

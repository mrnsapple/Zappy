/*
** EPITECH PROJECT, 2019
** Client
** File description:
** Info about client
*/

# ifndef MyClient
# define MyClient
# include "Player.hpp"

#include <string.h>

class Client {
public:
        Client();
        ~Client();
        int     startClient();
        void    setMachine(std::string);
        void    setName(std::string);
        void    setPort(int);  
protected:

private:
        std::string     createFifo(std::string );
      
        int     createPlayer();

private:        
        int _port;
        std::string _name;
        std::string _machine;
        std::vector<Player*> _players;

        // Communicate client player
        std::string     _fifo_read;
        
};

#endif /* !d */

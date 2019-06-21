/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai file
*/

#ifndef ai
#define ai

#include "Utils.hpp"
#include <cmath>  

class Ai {
	public:
		Ai(std::map<std::string, int> *, std::vector<std::map<std::string, int>> *,  std::map<std::string, int> *);
        ~Ai();
        std::vector<std::string> get_what_to_do();
    
    private:
        void  get_take_object(int amount, std::string);
        bool    time_to_create_player();
        int get_element(std::string);
        int get_stones();
        int get_item_pos(int location);

	protected:
	private:
        std::map<std::string, int> *_inventory;
        std::vector<std::map<std::string, int>> *_stuff_in_tiles;
        std::vector<std::string> _result;
		std::map<std::string, int> *_gems_finding;

};

#endif /* !ai */

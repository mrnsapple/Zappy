/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai file
*/

#ifndef ai
#define ai

#include "../../include/list.hpp"
#include "../utils/Utils.hpp"
#include <cmath>  

class Ai {
	public:
		Ai(std::map<std::string, int> *, std::vector<std::map<std::string, int>> *);
		~Ai();
        std::vector<std::string> get_what_to_do();
        std::vector<std::string> get_food();
         std::vector<std::string> get_item_pos(int);
	protected:
	private:
        std::map<std::string, int> *_inventory;
    std::vector<std::map<std::string, int>> *_stuff_in_tiles;
};

#endif /* !ai */

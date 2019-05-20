/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai file
*/

#include "Ai.hpp"

Ai::Ai(std::map<std::string, int> *inventory, 
    std::vector<std::map<std::string, int>> *stuf_in_tiles) :
    _inventory(inventory), _stuff_in_tiles(stuf_in_tiles)
{
}

Ai::~Ai()
{
}

std::vector<std::string> Ai::get_item_pos(int location)
{
    std::vector<std::string> result;
    int y_pos[] = {0, 3, 8, 15};
    int x_pos[] = {0, 2, 6, 12};
    std::string dir = "";

    for (int i = 0; i < 4; i++) {
        if (y_pos[i] <= location)
            for (int g = 0; g < i; g++)
                result.push_back("Forward\n");
    }
    for (int i = 0; i < 4; i++) {
        if (y_pos[i] <= location) {
            if (x_pos[i] < location)
                dir = "Left\n";
            else if (x_pos[i] > location)
                dir = "Right\n";
            for (int g = 0; g < std::abs(x_pos[i] - y_pos[i]); g++) {
                result.push_back(dir);
            }
        }
    }
    return result;
}


std::vector<std::string> Ai::get_food()
{
    std::vector<std::string> result;
    int location = 0;

    for (auto a: *_stuff_in_tiles) {
        if (a["food"] > 0)
            result = get_item_pos(location);
        location++;
    }
    return result;
}

std::vector<std::string> Ai::get_what_to_do()
{
    std::vector<std::string> result;

    if ((*_inventory)["food"] < 5)
        result = get_food();
    else
        result.clear();

    
    //std::cout << "print ai inventory:\n\n";
    //Utils::printMap(*_inventory);
    return result;
}


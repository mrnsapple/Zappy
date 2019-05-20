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

int Ai::get_item_pos(int location)
{
    std::vector<std::string> result;
    int y_pos[] = {0, 3, 8, 15};
    int x_pos[] = {0, 2, 6, 12};
    std::string dir = "";
    std::cout << "location:" << location <<"\n";
    for (int i = 0; i < 4; i++) {
        if (y_pos[i] >= location)  {
            std::cout << "i:" << i << "\n";
            for (int g = 0; g < i; g++)
                result.push_back("Forward\n");
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (y_pos[i] >= location) {
            if (x_pos[i] > location)
                result.push_back("Left\n");
            else if (x_pos[i] < location)
                result.push_back("Right\n");
            //std::cout <<"x:" << x_pos[i] << ", y:" << y_pos[i] <<  ",the abs:" <<std::abs(x_pos[i] - y_pos[i]) << "\n";
            for (int g = 0; g < std::abs(x_pos[i] - y_pos[i]); g++) {
                result.push_back("Forward\n");
            }
            break;
        }
    }
    _result = result;
    //std::cout <<" result\n";
    //for (auto a : result)
    //    std::cout << "pos:" << a;
    return (0);
}
/*
int main()
{
    Ai a;
    a.get_item_pos(0);
    std::cout << "other\n";

    a.get_item_pos(2);
    std::cout << "other\n";
    a.get_item_pos(3);
    std::cout << "other\n";
    a.get_item_pos(15);
    std::cout << "other\n";
}*/

void  Ai::get_take_object(int amount, std::string object)
{
    std::string take =  "Take ";

    take.append(object);
    take.append("\n");
    for (int i = 0; i < amount; i++)
        _result.push_back(take);
}

int Ai::get_food()
{
    int location = 0;

    for (auto a: *_stuff_in_tiles) {
        if (a["food"] > 0) {
            get_item_pos(location);
            get_take_object(a["food"], "food");
            return (0);
        }
        location++;
    }
    return 0;
}

std::vector<std::string> Ai::get_what_to_do()
{
    _result.clear();
    get_food();
    for (auto a : _result)
        std::cout << "pos:" << a;
   
    /*if ((*_inventory)["food"] < 5)
        result = get_food();
    else
        result.clear();
    */
    
    //std::cout << "print ai inventory:\n\n";
    //Utils::printMap(*_inventory);
    return _result;
}


/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai file
*/

#include "../../include/Ai.hpp"

Ai::Ai(std::map<std::string, int> *inventory, 
    std::vector<std::map<std::string, int>> *stuf_in_tiles,
     std::map<std::string, int> *gems_finding) :
    _inventory(inventory), _stuff_in_tiles(stuf_in_tiles), _gems_finding(gems_finding)
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
    //take.append("hiras");
    
    take.append("\n");
    for (int i = 0; i < amount; i++)
        _result.push_back(take);
}

int Ai::get_element(std::string element)
{
    int location = 0;

    _result.clear();
    for (auto a: *_stuff_in_tiles) {
        if (a[element] > 0) {
            get_item_pos(location);
            get_take_object(a[element], element);
            return (0);
        }
        location++;
    }
    return 0;
}

int Ai::get_stones()
{
    std::map<std::string, int>::iterator itr; 

    for (itr = (*_gems_finding).begin(); itr != (*_gems_finding).end(); itr++) { 
        //if (itr->second > 0) {
            if ((*_inventory)[itr->first] == 0)
                get_element(itr->first);
            //get_element("thystame");
            if (!_result.empty())
                break;
        //}
        //std::cout << '\t' << itr->first 
        //     << '\t' << itr->second << '\n'; 
    }
    return 0;
}

bool    Ai::time_to_create_player()
{
    if ((*_inventory)["linemate"] >= 1)
        return true;
    return false;
}

std::vector<std::string> Ai::get_what_to_do()
{
    _result.clear();
//            get_stones();

    if ((*_inventory)["food"] < 5)
        get_element("food");
    else if (time_to_create_player() == true)
        _result.push_back("Fork\n");
    else
        get_stones();
    //for (auto a : _result)
    //    std::cout << "pos:" << a;
    if (_result.empty()) {//If it does nocing,let's rotate
        _result.push_back("Right\n");
        _result.push_back("Right\n");
        for (int i = 0; i < 4; i++)    
            _result.push_back("Forward\n");

        std::cout << "Result is empty\n";
    }
    return _result;
}


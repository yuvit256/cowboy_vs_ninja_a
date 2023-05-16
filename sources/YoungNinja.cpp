#include "YoungNinja.hpp"
using namespace std;

namespace ariel
{
    YoungNinja::YoungNinja(string name, Point pos)
    {
        this->_name = name;
        this->_pos = pos;
        this->_speed = 14;
        this->_hp = 100;
    }
}
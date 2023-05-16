#include "OldNinja.hpp"
using namespace std;

namespace ariel
{
    OldNinja::OldNinja(string name, Point pos)
    {
        this->_name = name;
        this->_pos = pos;
        this->_speed = 8;
        this->_hp = 150;
    }
}
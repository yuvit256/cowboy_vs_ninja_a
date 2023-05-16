#include "TrainedNinja.hpp"
using namespace std;

namespace ariel
{
    TrainedNinja::TrainedNinja(string name, Point pos)
    {
        this->_name = name;
        this->_pos = pos;
        this->_speed = 12;
        this->_hp = 120;
    }
}
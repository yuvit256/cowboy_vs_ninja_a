#include "Ninja.hpp"
#include <cmath>
#include <iostream>

namespace ariel
{
    Ninja::Ninja(string name, Point pos)
    {
        this->_name = name;
        this->_pos = pos;
        this->_speed = 0;
    }

    Ninja::Ninja()
    {
        this->_name = "Yuval1";
        this->_pos = Point();
        this->_speed = 0;
    }

    void Ninja::move(Character *enemy)
    {
        Point dest = enemy->getLocation();
        Point new_pos = getLocation().moveTowards(getLocation(), dest, this->_speed);
        this->_pos = new_pos;
    }

    void Ninja::slash(Character *enemy)
    {
        if (this->isAlive() && (this->distance(enemy) <= 1))
        {
            enemy->hit(40);
        }
    }

    int Ninja::getSpeed()
    {
        return this->_speed;
    }
}
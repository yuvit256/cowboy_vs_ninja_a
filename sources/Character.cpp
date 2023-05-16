#include <iostream>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    Character::Character(Point pos, int hp1, string name)
    {
        this->_pos = pos;
        this->_hp = hp1;
        this->_name = name;
    }

    Character::Character()
    {
        this->_pos = Point();
        this->_hp = 100;
        this->_name = "Yuval";
    }

    bool Character::isAlive()
    {
        if (this->_hp > 0)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character *other)
    {
        double dis = this->_pos.distance(other->_pos);
        return dis;
    }

    void Character::hit(int dmg)
    {
        if (this->_hp > dmg)
        {
            this->_hp -= dmg;
            return;
        }
        this->_hp = 0;
    }

    string Character::getName()
    {
        return this->_name;
    }

    Point Character::getLocation()
    {
        return this->_pos;
    }

    int Character::getHp()
    {
        return this->_hp;
    }

    string Character::print()
    {
        return "";
    }
}
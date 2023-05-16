#include "Cowboy.hpp"
using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name, Point pos)
    {
        this->_name = name;
        this->_pos = pos;
        this->_ammo = 6;
        this->_hp = 110;
    }

    bool Cowboy::hasboolets()
    {
        if (this->_ammo > 0)
        {
            return true;
        }
        return false;
    }

    void Cowboy::shoot(Character *enemy)
    {
        if ((this->isAlive()) && (this->hasboolets()))
        {
            enemy->hit(10);
            this->_ammo--;
        }
    }

    void Cowboy::reload()
    {
        this->_ammo = 6;
    }

    int Cowboy::getAmmo()
    {
        return this->_ammo;
    }
}
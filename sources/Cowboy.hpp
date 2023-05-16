#ifndef COWBOY_H
#define COWBOY_H

#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int _ammo;
    public:
        Cowboy(string name, Point pos);
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        int getAmmo();
    };
}

#endif
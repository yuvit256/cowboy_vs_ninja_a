#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
        protected:
            Point _pos;
            int _hp;
            string _name; 
        public:
            Character(Point pos, int hp1, string name);
            Character();
            bool isAlive();
            double distance(Character *other);
            void hit(int dmg);
            string getName();
            Point getLocation();
            string print();
            int getHp();
    };
};

#endif
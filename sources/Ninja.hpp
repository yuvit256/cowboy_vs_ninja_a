#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
using namespace std;

namespace ariel {
    class Ninja : public Character {
    protected:
        int _speed;
    public:
        Ninja(string name, Point pos);
        Ninja();
        void move(Character *enemy);
        void slash(Character *enemy);
        int getSpeed();
    };
}

#endif 
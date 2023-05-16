#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point pos);
    };
}

#endif
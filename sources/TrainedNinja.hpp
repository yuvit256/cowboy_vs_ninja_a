#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point pos);
    };
}

#endif
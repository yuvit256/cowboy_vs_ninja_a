#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;

namespace ariel
{
    class Team
    {
    private:
        vector<Character *> _group;
    public:
        Team(Character *leader);
        virtual ~Team();
        void add(Character *member);
        void attack(Team *enemy);
        int stillAlive();
        void print();
    };
};

#endif
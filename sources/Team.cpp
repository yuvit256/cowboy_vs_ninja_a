#include "Team.hpp"
using namespace std;

namespace ariel
{
    Team::Team(Character *leader)
    {
        this->_group.push_back(leader);
    }

    int Team::stillAlive()
    {
        int live = 0;
        // for (auto member : this->_group)
        // {
        //     if (member->isAlive())
        //     {
        //         live++;
        //     }
        // }
        return live;
    }

    Team::~Team()
    {
        for (auto member : this->_group)
        {
            delete member;
        }
    }

    void Team::add(Character *member)
    {
        if (this->_group.size() < 10)
        {
            this->_group.push_back(member);
        }
    }

    void Team::attack(Team *enemy)
    {
    }

    void Team::print()
    {
    }
}
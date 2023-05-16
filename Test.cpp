#include "doctest.h"
#include "sources/Team.hpp"

using namespace ariel;

TEST_CASE("Testing the Cowboy class")
{
    Point p(1, 2);
    Cowboy *c = new Cowboy("Mecree", p);
    CHECK(c->getName() == "Mecree");
    CHECK((c->getLocation() == p));
    CHECK((c->getAmmo() == 6));
    CHECK((c->getHp() == 110));
    Team team(c);
}

TEST_CASE("Testing the YoungNinja class")
{
    Point p(10, 20);
    YoungNinja *y = new YoungNinja("Genji", p);
    CHECK(y->getName() == "Genji");
    CHECK((y->getLocation() == p));
    CHECK((y->getSpeed() == 14));
    CHECK((y->getHp() == 100));
    Team team(y);
}

TEST_CASE("Testing the TrainedNinja class")
{
    Point p(8, 8);
    TrainedNinja *t = new TrainedNinja("Yuval", p);
    CHECK(t->getName() == "Yuval");
    CHECK((t->getLocation() == p));
    CHECK((t->getSpeed() == 12));
    CHECK((t->getHp() == 120));
    CHECK(t->isAlive());
    Team team(t);
}

TEST_CASE("Testing the OldNinja class")
{
    Point p(6, 9);
    OldNinja *t = new OldNinja("Yuval", p);
    CHECK(t->getName() == "Yuval");
    CHECK((t->getLocation() == p));
    CHECK((t->getSpeed() == 8));
    CHECK((t->getHp() == 150));
    CHECK(t->isAlive());
    Team team(t);
}

TEST_CASE("Testing the Point class")
{
    Point p1(1, 2);
    Point p2(4, 6);
    CHECK_EQ(p1.getX(), 1);
    CHECK_EQ(p2.getX(), 4);
    CHECK_EQ(p1.getY(), 2);
    CHECK_EQ(p2.getY(), 6);
    bool a = p1.distance(p2) == 5;
    CHECK(a);
    CHECK_EQ(p1.distance(p2), p2.distance(p1));
    CHECK_EQ(p2.distance(p2), 0);
}

TEST_CASE("Testing the Character class")
{
    Point p(1, 2);
    Character *c = new Character(p, 200, "Mercy");
    Point p2(4, 6);
    Character *c2 = new Character(p2, 175, "Snowball");
    CHECK_EQ(c->getHp(), 200);
    CHECK_EQ(c2->getHp(), 175);
    c->hit(100);
    c2->hit(200);
    CHECK(c->isAlive());
    CHECK_FALSE(c2->isAlive());
    CHECK_EQ(c2->distance(c), 5);
    Team team(c);
    team.add(c2);
}

TEST_CASE("Testing the Team class")
{
    Point p(1, 2);
    Character *c = new Character(p, 200, "Reaper");
    Point p2(4, 6);
    Character *c2 = new Character(p2, 175, "Soldier76");
    Team team(c2);
    team.add(c);
    CHECK_EQ(team.stillAlive(), 2);
}

TEST_CASE("Testing the Cowboy class continue")
{
    Point p1(1, 2);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(10, 20);
    YoungNinja *y = new YoungNinja("Genji", p2);
    c->shoot(y);
    CHECK((c->getAmmo() == 5));
    CHECK((y->getHp() == 90));
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the YoungNinja class continue")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(15, 0);
    YoungNinja *y = new YoungNinja("Genji", p2);
    y->slash(c);
    CHECK(c->getHp() == 110);
    y->move(c);
    y->slash(c);
    CHECK(c->getHp() == 70);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the OldNinja class continue")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(9, 0);
    OldNinja *y = new OldNinja("Genji", p2);
    y->slash(c);
    CHECK(c->getHp() == 110);
    y->move(c);
    y->slash(c);
    CHECK(c->getHp() == 70);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the TrainedNinja class continue")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(13, 0);
    TrainedNinja *y = new TrainedNinja("Genji", p2);
    y->slash(c);
    CHECK(c->getHp() == 110);
    y->move(c);
    y->slash(c);
    CHECK(c->getHp() == 70);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the Cowboy class - shoot again")
{
    Point p1(1, 2);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(10, 20);
    YoungNinja *y = new YoungNinja("Genji", p2);
    c->shoot(y);
    c->shoot(y);
    CHECK((c->getAmmo() == 4));
    CHECK((y->getHp() == 80));
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the YoungNinja class - slash again")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(15, 0);
    YoungNinja *y = new YoungNinja("Genji", p2);
    y->move(c);
    y->slash(c);
    y->slash(c);
    CHECK(c->getHp() == 30);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the OldNinja class - slash again")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(9, 0);
    OldNinja *y = new OldNinja("Genji", p2);
    y->move(c);
    y->slash(c);
    y->slash(c);
    CHECK(c->getHp() == 30);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the TrainedNinja class - slash again")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(13, 0);
    TrainedNinja *y = new TrainedNinja("Genji", p2);
    y->move(c);
    y->slash(c);
    y->slash(c);
    CHECK(c->getHp() == 30);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the Cowboy class - shoot multiple times")
{
    Point p1(1, 2);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(10, 20);
    YoungNinja *y = new YoungNinja("Genji", p2);
    for (int i = 0; i < 6; i++)
    {
        c->shoot(y);
    }
    CHECK((c->getAmmo() == 0));
    CHECK((y->getHp() == 40));
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the YoungNinja class - slash multiple times")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(15, 0);
    YoungNinja *y = new YoungNinja("Genji", p2);
    y->move(c);
    for (int i = 0; i < 10; i++)
    {
        y->slash(c);
    }
    CHECK(c->getHp() == 0);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the OldNinja class - slash multiple times")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(9, 0);
    OldNinja *y = new OldNinja("Genji", p2);
    y->move(c);
    for (int i = 0; i < 10; i++)
    {
        y->slash(c);
    }
    CHECK(c->getHp() == 0);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the TrainedNinja class - slash multiple times")
{
    Point p1(0, 0);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(13, 0);
    TrainedNinja *y = new TrainedNinja("Genji", p2);
    y->move(c);
    for (int i = 0; i < 10; i++)
    {
        y->slash(c);
    }
    CHECK(c->getHp() == 0);
    Team team(c);
    team.add(y);
}

TEST_CASE("Testing the Cowboy class - shoot multiple times, then reload")
{
    Point p1(1, 2);
    Cowboy *c = new Cowboy("Mecree", p1);
    Point p2(10, 20);
    YoungNinja *y = new YoungNinja("Genji", p2);
    for (int i = 0; i < 10; i++)
    {
        c->shoot(y);
    }
    c->reload();
    CHECK((c->getAmmo() == 6));
    CHECK((y->getHp() == 40));
    Team team(c);
    team.add(y);
}

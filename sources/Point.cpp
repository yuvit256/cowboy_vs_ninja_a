#include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace std;

namespace ariel
{
    Point::Point(double x, double y)
    {
        this->_x = x;
        this->_y = y;
    }

    Point::Point()
    {
        this->_x = 0;
        this->_y = 0;
    }

    double Point::distance(Point &other)
    {
        double dis = pow((this->_x - other._x), 2) + pow((this->_y - other._y), 2);
        return sqrt(abs(dis));
    }

    void Point::print()
    {
        cout << "(" << this->_x << "," << this->_y << ")";
    }

    Point Point::moveTowards(Point src, Point dst, double dis)
    {
        double dis_SRC_to_DST = src.distance(dst);
        if (dis_SRC_to_DST <= dis)
        {
            return dst;
        }
        double ratio = dis / dis_SRC_to_DST;
        double X = src.getX() + (dst.getX() - src.getX()) * ratio;
        double Y = src.getY() + (dst.getY() - src.getY()) * ratio;
        return Point(X, Y);
    }

    double Point::getX() const
    {
        return this->_x;
    }

    double Point::getY() const
    {
        return this->_y;
    }

    bool operator==(Point const &p1, Point const &p2)
    {
        if ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY()))
        {
            return true;
        }
        return false;
    }
}
#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

namespace ariel
{
    class Point
    {
        private:
            double _x;
            double _y;
        public:
            Point(double , double );
            Point();
            double distance(Point &other);
            void print();
            Point moveTowards(Point , Point, double );
            double getX() const;
            double getY() const;
            friend bool operator==(const Point &, const Point &);
    };
};

#endif
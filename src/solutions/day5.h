#pragma once

#include <string>

namespace Solution
{
namespace Day5
{

void day5();
int index(int x, int y);

struct Point
{
    int x;
    int y;

    Point()
    :x(0), y(0)
    {
    }

    Point(int x1, int y1)
    :x(x1), y(y1)
    {
    }

};

void populatePoint(Point* point, const std::string& pointString);


}
}
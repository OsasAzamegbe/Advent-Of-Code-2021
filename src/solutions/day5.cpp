#include <day5.h>

#include <iostream>
#include <fstream>
#include <sstream>


namespace Solution
{
namespace Day5
{

const int SIZE = 1000;

void day5()
{
    std::string line;
    std::string leftPointString;
    std::string rightPointString;
    std::string delim = " -> ";
    std::ifstream inputFile("testfiles/day5test.txt");
    int pos, lineStart = 0, lineEnd = 0;
    int grid[SIZE * SIZE] = {};

    while(std::getline(inputFile, line)) {
        pos = line.find(delim);
        leftPointString = line.substr(0, pos);
        rightPointString = line.substr(pos + delim.size());
        Point leftPoint, rightPoint;
        populatePoint(&leftPoint, leftPointString);
        populatePoint(&rightPoint, rightPointString);

        if(leftPoint.x == rightPoint.x) {
            if (leftPoint.y < rightPoint.y) {
                lineStart = leftPoint.y;
                lineEnd = rightPoint.y;
            } else {
                lineStart = rightPoint.y;
                lineEnd = leftPoint.y;
            }
            for (int i = lineStart; i <= lineEnd; ++i) {
                ++grid[index(leftPoint.x, i)];
            }
        } else if(leftPoint.y == rightPoint.y) {
            if (leftPoint.x < rightPoint.x) {
                lineStart = leftPoint.x;
                lineEnd = rightPoint.x;
            } else {
                lineStart = rightPoint.x;
                lineEnd = leftPoint.x;
            }
            for (int i = lineStart; i <= lineEnd; ++i) {
                ++grid[index(i, leftPoint.y)];
            }
        }
        
    }

    int numOverlaps = 0;
    for (int i = 0; i < SIZE * SIZE; ++i) {
        if (grid[i] > 1) {
            ++numOverlaps;
        }
    }

    std::cout << "Answer to day5 part one: " << numOverlaps << std::endl;
}

int index(int x, int y)
{
    return (x * SIZE) + y;
}

void populatePoint(Point* point, const std::string& pointString)
{
    std::stringstream ss(pointString);
    std::string xString, yString;

    std::getline(ss, xString, ',');
    std::getline(ss, yString, ',');

    point->x = std::stoi(xString);
    point->y = std::stoi(yString);

}

}
}
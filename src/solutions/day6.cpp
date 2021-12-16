#include <day6.h>

#include <string>
#include <deque>
#include <iostream>
#include <fstream>
#include <sstream>


namespace Solution
{
namespace Day6
{

void day6()
{
    std::ifstream inputFile("testfiles/day6test.txt");
    std::string line;
    std::getline(inputFile, line);

    std::stringstream numberStream(line);
    std::string num;
    std::deque<long long> fishGroups(9); //group fishes with same num of days together
    while(getline(numberStream, num, ',')) {
        ++fishGroups[std::stoi(num)];
    }
    long long newFishes;
    for (int day = 0; day < 256; ++day) {
        if (day == 80) {
            std::cout << "Answer to day6 part one: " << getNumberOfFishes(fishGroups) << std::endl;

        }
        newFishes = fishGroups.front();
        fishGroups.pop_front();
        fishGroups.push_back(newFishes);
        fishGroups[6] += newFishes;
    }

    std::cout << "Answer to day6 part two: " << getNumberOfFishes(fishGroups) << std::endl;
}

long long getNumberOfFishes(const std::deque<long long>& fishGroups)
{
    long long numOfFishes = 0;
    for (int i = 0; i < fishGroups.size(); ++i) {
        numOfFishes += fishGroups[i];
    }

    return numOfFishes;
}

}
}
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
    std::deque<int> fishGroups(9); //group fishes with same num of days together
    while(getline(numberStream, num, ',')) {
        ++fishGroups[std::stoi(num)];
    }
    int newFishes;
    for (int day = 0; day < 80; ++day) {
        newFishes = fishGroups.front();
        fishGroups.pop_front();
        fishGroups.push_back(newFishes);
        fishGroups[6] += newFishes;
    }

    int numOfFishes = 0;
    for (int i = 0; i < fishGroups.size(); ++i) {
        numOfFishes += fishGroups[i];
    }

    std::cout << "Answer to day5 part one: " << numOfFishes << std::endl;
}

}
}
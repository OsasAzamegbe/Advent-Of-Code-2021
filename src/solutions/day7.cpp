#include <day7.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <numeric>
#include <cmath> 
#include <algorithm>


namespace Solution
{
namespace Day7
{

void day7()
{
    std::ifstream inputFile("testfiles/day7test.txt");
    std::string num;
    std::vector<int> subs;
    int n, minSub = INT_MAX, maxSub = INT_MIN;
    while(getline(inputFile, num, ',')) {
        n = std::stoi(num);
        if (n < minSub) {
            minSub = n;
        }
        if (n > maxSub) {
            maxSub = n;
        }
        subs.push_back(n);
    }

    std::vector<int> fuelSpent;
    int totalFuel;
    for(int pos = minSub; pos <= maxSub; ++pos) {
        totalFuel = std::accumulate(subs.begin(), subs.end(), 0, [&pos](int total, int sub)
        {
            return total + std::abs(sub - pos);
        });

        fuelSpent.push_back(totalFuel);
    }

    int minFuelSpent = *(std::min_element(fuelSpent.begin(), fuelSpent.end()));

    std::cout << "Answer to day 7 part one: " << minFuelSpent << std::endl;


}

}
}
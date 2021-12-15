#pragma once
#include <string>
#include <vector>
#include <algorithm>


namespace Solution
{
namespace Day3
{

void day3();
void day3PartTwo();
template<typename BitCriteriaFunc>
int readRating(std::vector<std::string> data, BitCriteriaFunc&& bitCriteria)
{
    if (data.empty()) {
        return 0;
    }
    bool isDataSizeOne = data.size() == 1;
    char mostcommonBit;

    for(int i = 0; i < data[0].size() && !isDataSizeOne; ++i) {

        int ones = 0, zeroes = 0;
        for(int j = 0; j < data.size() && !isDataSizeOne; ++j) {
            if (data[j][i] == '1') {
                ++ones;
            } else {
                ++zeroes;
            }
        }

        mostcommonBit = bitCriteria(ones, zeroes);
        std::vector<std::string> newData;
        std::copy_if(data.begin(), data.end(), std::back_inserter(newData), [&mostcommonBit, &i](const std::string& binaryString)
        {
            return binaryString[i] == mostcommonBit; 
        });

        data = newData;
        isDataSizeOne == data.size() == 1;
    }

    return std::stoi(data[0], nullptr, 2);

}

}
}
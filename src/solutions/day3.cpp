#include <day3.h>

#include <iostream>
#include <fstream>


namespace Solution
{
namespace Day3
{

void day3()
{
    std::string binaryString;
    std::ifstream inputFile("day3test.txt");
    std::vector<int> onesFreq;
    std::vector<int> zeroesFreq;

    while(std::getline(inputFile, binaryString)) {
        for (int i = 0; i < binaryString.size(); ++i) {
            if(i == onesFreq.size()) {
                onesFreq.push_back(0);
                zeroesFreq.push_back(0);
            }

            if(binaryString[i] == '1') {
                ++onesFreq[i];
            } else {
                ++zeroesFreq[i];
            }
        }
    }

    std::string gammaString;
    std::string epsilonString;
    for (int i = 0; i < onesFreq.size(); ++i) {
        if (onesFreq[i] > zeroesFreq[i]) {
            gammaString.push_back('1');
            epsilonString.push_back('0');
        } else {
            gammaString.push_back('0');
            epsilonString.push_back('1');
        }
    }
    int gammaRate = std::stoi(gammaString, nullptr, 2);
    int epsilonRate = std::stoi(epsilonString, nullptr, 2);

    std::cout << "Answer to day3 part one: " << gammaRate * epsilonRate << std::endl;
}

void day3PartTwo() 
{
    std::string binaryString;
    std::ifstream inputFile("day3test.txt");
    std::vector<std::string> data;
    while (getline(inputFile, binaryString)) {
        data.push_back(binaryString);
    }

    int oxygenGeneratorRating = readRating(data, [](int ones, int zeroes) {
        return ones >= zeroes ? '1' : '0';
    });
    int co2ScrubberRating = readRating(data, [](int ones, int zeroes) {
        return ones < zeroes ? '1' : '0';
    });

    std::cout << "Answer to day3 part two: " << oxygenGeneratorRating * co2ScrubberRating << std::endl;
}


}
}
#include <day8.h>

#include <iostream>
#include <fstream>
#include <sstream>


namespace Solution
{
namespace Day8
{

void day8()
{

    // segments
    //  3333
    // 7    5
    // 7    5
    //  4444
    // 2    6 
    // 2    6
    //  1111

    //represents the sum of segments for a given number from 0 -> 9 from above representation
    int NUMBER_VALUES[29] = {}; // max value is 28, hence size of 29
    NUMBER_VALUES[24] = 0;
    NUMBER_VALUES[11] = 1;
    NUMBER_VALUES[15] = 2;
    NUMBER_VALUES[19] = 3;
    NUMBER_VALUES[22] = 4;
    NUMBER_VALUES[21] = 5;
    NUMBER_VALUES[23] = 6;
    NUMBER_VALUES[14] = 7;
    NUMBER_VALUES[28] = 8;
    NUMBER_VALUES[26] = 9;

    std::ifstream inputFile("testfiles/day8test.txt");
    std::string line, uniqueSignalsString, outputValuesString, digit;

    int numUniqueDigits = 0;
    long totalOutputValues = 0;
    while(std::getline(inputFile, line)) {
        std::vector<std::string> uniqueSignals, outputValues;
        std::stringstream ss(line);

        std::getline(ss, uniqueSignalsString, '|'); //to get first part before delimiter
        std::stringstream uniqueSignalsStream(uniqueSignalsString);
        while(std::getline(uniqueSignalsStream, digit, ' ')) {
            if (digit.empty()) {
                continue;
            }
            uniqueSignals.push_back(digit);
        }

        std::getline(ss, outputValuesString, '|'); //to get second part after delimiter
        std::stringstream outputValuesStream(outputValuesString);
        while(std::getline(outputValuesStream, digit, ' ')) {
            if (digit.empty()) {
                continue;
            }
            if (isUniqueDigit(digit)) {
                ++numUniqueDigits;
            }
            outputValues.push_back(digit);
        }

        totalOutputValues += parseOutputValuesToDecimal(NUMBER_VALUES, uniqueSignals, outputValues);
    }

    std::cout << "Answer to day 8 part one: " << numUniqueDigits << std::endl;
    std::cout << "Answer to day 8 part two: " << totalOutputValues << std::endl;

}

bool isUniqueDigit(const std::string& digit)
{
    return digit.size() == 2 || digit.size() == 3 || digit.size() == 4 || digit.size() == 7;
}

void decodeUniqueSignals(int* segmentMap, const std::vector<std::string>& uniqueSignals)
{
    std::string one, seven, four, eight;
    std::vector<std::string> fives, sixes;
    for(const std::string& digit : uniqueSignals) {
        switch(digit.size()) {
            case 2:
                one = digit;
                break;
            case 3:
                seven = digit;
                break;
            case 4:
                four = digit;
                break;
            case 5:
                fives.push_back(digit);
                break;
            case 6:
                sixes.push_back(digit);
                break;
            case 7:
                eight = digit;
                break;
            default:
                std::cout << "something is wring with size of digits" << std::endl;
        }
    }
    //get first segment: 3
    for(char letter : seven) {
        if(one.find(letter) == std::string::npos) {
            segmentMap[index(letter)] = 3;
        }
    }

    //get next two segments: 5, 6
    int counter = 0;
    for(const std::string digit : sixes) {
        if (digit.find(one[0]) != std::string::npos) {
            ++counter;
        }
    }
    if (counter == 2) {
        segmentMap[index(one[0])] = 5;
        segmentMap[index(one[1])] = 6;
    } else {
        segmentMap[index(one[0])] = 6;
        segmentMap[index(one[1])] = 5;       
    }

    //get next two segments: 4, 7
    std::string twoUniqueUnknown = "";
    for (char letter : four) {
        if (one.find(letter) == std::string::npos) {
            twoUniqueUnknown += letter;
        }
    }
    counter = 0;
    for (const std::string digit : fives) {
        if (digit.find(twoUniqueUnknown[0]) != std::string::npos) {
            ++counter;
        }
    }
    if (counter == 3) {
        segmentMap[index(twoUniqueUnknown[0])] = 4;
        segmentMap[index(twoUniqueUnknown[1])] = 7;
    } else {
        segmentMap[index(twoUniqueUnknown[0])] = 7;
        segmentMap[index(twoUniqueUnknown[1])] = 4;       
    }

    //get last two segments: 1, 2
    twoUniqueUnknown = "";
    for(char letter : eight) {
        if(!segmentMap[index(letter)]) {
            twoUniqueUnknown += letter;
        }
    }
    counter = 0;
    for (const std::string digit : fives) {
        if (digit.find(twoUniqueUnknown[0]) != std::string::npos) {
            ++counter;
        }
    }
    if (counter == 3) {
        segmentMap[index(twoUniqueUnknown[0])] = 1;
        segmentMap[index(twoUniqueUnknown[1])] = 2;
    } else {
        segmentMap[index(twoUniqueUnknown[0])] = 2;
        segmentMap[index(twoUniqueUnknown[1])] = 1;       
    }

}

int parseOutputValuesToDecimal(int* NUMBER_VALUES, const std::vector<std::string>& uniqueSignals, const std::vector<std::string>& outputValues)
{

    int uniqueSegmentMap[7] = {}; // a->g index 0->6. maps letter to segment value.
    decodeUniqueSignals(uniqueSegmentMap, uniqueSignals);

    int actual_num = 0;
    for (const std::string& digit : outputValues) {
        int number_value = 0;
        for (char letter : digit) {
            number_value += uniqueSegmentMap[index(letter)];
        }
        actual_num = actual_num * 10 + NUMBER_VALUES[number_value];
    }


    return actual_num;
}

int index(char letter)
{
    return letter - 'a';
}

}
}
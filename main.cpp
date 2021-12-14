#include <util.h>
#include <day1.h>
#include <day2.h>

#include <string>
#include <iostream>
#include <vector>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        print("Must specify a solution date as an argument.\nFor example:\n`aoc day1` - runs the day1.cpp solution file.");
        return 1;
    }

    static const std::string day1 = "day1";
    static const std::string day2 = "day2";
    std::vector<std::string> validArguments;
    validArguments.push_back(day1);
    validArguments.push_back("day2");
    
    if (argv[1] == day1) {
        Solution::Day1::day1();
    } else if (argv[1] == day2) {
        Solution::Day2::day2();
    } else {
        std::string message = "Unkown argument passed: " + std::string(argv[1]) + ".\nValid arguments are:";
        print(message);
        print(validArguments.begin(), validArguments.end());
    }

    return 0;
}
#include <util.h>
#include <day1.h>
#include <day2.h>
#include <day3.h>
#include <day4.h>
#include <day5.h>
#include <day6.h>
#include <day7.h>

#include <string>
#include <iostream>
#include <vector>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        print("Must specify a solution date as an argument.\nFor example:\n`aoc day1` - runs the day1.cpp solution file.");
        return 1;
    }
    
    if (argv[1] == "day1") {
        Solution::Day1::day1();
    } else if (argv[1] == "day2") {
        Solution::Day2::day2();
    } else if (argv[1] == "day3") {
        Solution::Day3::day3();
        Solution::Day3::day3PartTwo();
    } else if (argv[1] == "day4") {
        Solution::Day4::day4();
    } else if (argv[1] == "day5") {
        Solution::Day5::day5();
    }  else if (argv[1] == "day6") {
        Solution::Day6::day6();
    }  else if (argv[1] == "day7") {
        Solution::Day7::day7();
    }  else {
        std::string message = "Unkown argument passed: " + std::string(argv[1]) + ".\nValid arguments are 'day1' through to 'day7'";
        print(message);
    }

    return 0;
}
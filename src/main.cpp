#include <util.h>
#include <day1.h>
#include <day2.h>
#include <day3.h>
#include <day4.h>
#include <day5.h>
#include <day6.h>
#include <day7.h>
#include <day8.h>
#include <day9.h>
#include <day10.h>
#include <day11.h>
#include <day20.h>

#include <string>
#include <iostream>
#include <vector>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        print("Must specify a solution date as an argument.\nFor example:\n`aoc day1` - runs the day1.cpp solution file.");
        return 1;
    }
    
    if (argv[1] == std::string("day1")) {
        Solution::Day1::day1();
    } else if (argv[1] == std::string("day2")) {
        Solution::Day2::day2();
    } else if (argv[1] == std::string("day3")) {
        Solution::Day3::day3();
        Solution::Day3::day3PartTwo();
    } else if (argv[1] == std::string("day4")) {
        Solution::Day4::day4();
    } else if (argv[1] == std::string("day5")) {
        Solution::Day5::day5();
    } else if (argv[1] == std::string("day6")) {
        Solution::Day6::day6();
    } else if (argv[1] == std::string("day7")) {
        Solution::Day7::day7();
    } else if (argv[1] == std::string("day8")) {
        Solution::Day8::day8();
    } else if (argv[1] == std::string("day9")) {
        Solution::Day9::day9();
    } else if (argv[1] == std::string("day10")) {
        Solution::Day10::day10();
    } else if (argv[1] == std::string("day11")) {
        Solution::Day11::day11();
    } else if (argv[1] == std::string("day20")) {
        Solution::Day20::day20();
    } else {
        std::string message = "Unkown argument passed: " + std::string(argv[1]) + ".\nValid arguments are 'day1' - 'day11' and 'day20'";
        print(message);
    }

    return 0;
}
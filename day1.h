#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

namespace Solution
{
namespace Day1
{

void day1();
void readInput(std::vector<int>& inputVector, const char* filename);
int solve(const std::vector<int>& inputVector);
int solvePartTwo(const std::vector<int>& iv);

}
}

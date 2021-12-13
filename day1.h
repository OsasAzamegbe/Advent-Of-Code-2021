#pragma once
#include <iostream>
#include <fstream>
#include <vector>

namespace Solution
{
namespace Day1
{

void day1();
void readInput(std::vector<int>& inputVector, const char* filename);
int solve(const std::vector<int>& inputVector);

}
}

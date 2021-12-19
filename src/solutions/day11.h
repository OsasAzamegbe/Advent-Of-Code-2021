#pragma once

#include <vector>


namespace Solution
{
namespace Day11
{

void day11();
int nextStep(int* hasFlashed, std::vector<std::vector<int>>& energyLevels, int row, int col);
bool isValidCell(int row, int col);
int index(int row, int col);

}
}
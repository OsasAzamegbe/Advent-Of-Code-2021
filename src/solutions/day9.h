#pragma once

#include <vector>

namespace Solution
{
namespace Day9
{

void day9();
int getSizeOfBasin(std::vector<std::vector<bool>>& seen, const std::vector<std::vector<int>>& heightMap, int row, int col, int prevHeight);

}
}
#include <day9.h>

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


namespace Solution
{
namespace Day9
{

void day9()
{
    std::vector<std::vector<int>> heightMap;

    std::ifstream inputFile("testfiles/day9test.txt");
    std::string line;
    while(std::getline(inputFile, line)) {
        heightMap.push_back(std::vector<int>());
        for(char num : line) {
            heightMap.back().push_back(num - '0');
        }
    }

    int rows = heightMap.size(), cols = heightMap[0].size();
    int rowDelta[4] = {1, -1, 0, 0};
    int colDelta[4] = {0, 0, 1, -1};
    int totalRiskLevel = 0;
    std::vector<std::vector<bool>> seen(rows, std::vector<bool>(cols, false));
    int maxBasins[3] = {};

    for(int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            bool isLowPoint = true;
            for (int d = 0; d < 4; ++d) {
                int newRow = row + rowDelta[d], newCol = col + colDelta[d];
                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols 
                    && heightMap[row][col] >= heightMap[newRow][newCol]) {
                    isLowPoint = false;
                    break;
                }
            }

            if(isLowPoint) {
                totalRiskLevel += heightMap[row][col] + 1;
                int basinSize = getSizeOfBasin(seen, heightMap, row, col, -1);
                std::cout << basinSize << std::endl;
                int* minimum = std::min_element(maxBasins, maxBasins + 3);
                if (*minimum < basinSize) {
                    *minimum = basinSize;
                }
            }
        }
    }
    std::cout << "Answer to day 9 part one: " << totalRiskLevel << std::endl;
    std::cout << "Answer to day 9 part two: " << maxBasins[0] * maxBasins[1] * maxBasins[2] << std::endl;

}

int getSizeOfBasin(std::vector<std::vector<bool>>& seen, const std::vector<std::vector<int>>& heightMap, int row, int col, int prevHeight)
{
    if(row < 0 || col < 0 || row == heightMap.size() || col == heightMap[0].size() 
        || seen[row][col] || heightMap[row][col] == 9 || prevHeight >= heightMap[row][col]) {
        return 0;
    }

    seen[row][col] = true;
    int rowDelta[4] = {1, -1, 0, 0};
    int colDelta[4] = {0, 0, 1, -1};
    int basinSize = 1;

    for (int d = 0; d < 4; ++d) {
        int newRow = row + rowDelta[d], newCol = col + colDelta[d];
        basinSize += getSizeOfBasin(seen, heightMap, newRow, newCol, heightMap[row][col]);
    }

    return basinSize;

}

}
}
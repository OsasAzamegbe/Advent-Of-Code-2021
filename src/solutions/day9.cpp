#include <day9.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


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

    int rowDelta[4] = {1, -1, 0, 0};
    int colDelta[4] = {0, 0, 1, -1};
    int totalRiskLevel = 0;

    for(int row = 0; row < heightMap.size(); ++row) {
        for (int col = 0; col < heightMap[0].size(); ++col) {
            bool isLowPoint = true;
            for (int d = 0; d < 4; ++d) {
                int newRow = row + rowDelta[d], newCol = col + colDelta[d];
                if (newRow >= 0 && newCol >= 0 && newRow < heightMap.size() && newCol < heightMap[0].size() 
                    && heightMap[row][col] >= heightMap[newRow][newCol]) {
                    isLowPoint = false;
                    break;
                }
            }

            if(isLowPoint) {
                totalRiskLevel += heightMap[row][col] + 1;
            }
        }
    }
    std::cout << "Answer to day 9 part one: " << totalRiskLevel << std::endl;

}

}
}
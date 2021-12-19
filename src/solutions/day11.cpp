#include <day11.h>

#include <fstream>
#include <iostream>
#include <string>


namespace Solution
{
namespace Day11
{

void day11()
{
    std::vector<std::vector<int>> energyLevels;

    std::ifstream inputFile("testfiles/day11test.txt");
    std::string line;
    while(std::getline(inputFile, line)) {
        energyLevels.push_back(std::vector<int>());
        for(char num : line) {
            energyLevels.back().push_back(num - '0');
        }
    }

    int totalFlashes = 0, stepAllFlashed = 0;
    bool allFlashed = false;
    for (int step = 0; !allFlashed || step < 100; ++step) {
        int hasFlashed[100] = {}; 
        int flashes = 0;
        for(int row = 0; row < 10; ++row) {
            for(int col = 0; col < 10; ++col) { 
                flashes += nextStep(hasFlashed, energyLevels, row, col);
            }
        }
        if (step < 100) {
            totalFlashes += flashes;
        }
        if (flashes == 100) {
            allFlashed = true;
            stepAllFlashed = step + 1;
        }
    }

    std::cout << "Answer to day 11 part one: " << totalFlashes << std::endl;
    std::cout << "Answer to day 11 part two: " << stepAllFlashed << std::endl;


}

int nextStep(int* hasFlashed, std::vector<std::vector<int>>& energyLevels, int row, int col)
{
    if (!isValidCell(row, col) || hasFlashed[index(row, col)]) {
        return 0;
    }
    int flashes = 0;

    if(energyLevels[row][col] == 9) {
        ++flashes;
        int rowDelta[] = {0, 0, 1, -1, 1, -1, 1, -1};
        int colDelta[] = {1, -1, 0, 0, 1, -1, -1, 1};
        hasFlashed[index(row, col)] = 1;

        for (int i = 0; i < 8; ++i) {
            flashes += nextStep(hasFlashed, energyLevels, row + rowDelta[i], col + colDelta[i]);
        }
        
        energyLevels[row][col] = 0;
    } else {
        ++energyLevels[row][col];
    }

    return flashes;
    
}

bool isValidCell(int row, int col)
{
    return row >= 0 && col >= 0 && row < 10 && col < 10;
}

int index(int row, int col)
{
    return row * 10 + col;
}

}
}
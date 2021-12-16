#include <day4.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>


namespace Solution
{
namespace Day4
{

bool Board::isBingo()
{
    for(int i = 0; i < 5 && !hasAlreadyBingoed; ++i) {
        if (rows[i] == 5 || cols[i] == 5) {
            hasAlreadyBingoed = true;
        }
    }
    return hasAlreadyBingoed;
}

bool day4()
{
    std::vector<Board*> boards;
    std::vector<int> bingoNumbers;
    std::unordered_map<int, std::vector<BoardFinder>> numberBoardMap;
    
    std::string line;
    std::ifstream inputFile("testfiles/day4test.txt");

    if (std::getline(inputFile, line)) {
        //parse random bingo numbers to boards vector
        std::stringstream numStream(line);
        std::string num;
        while(std::getline(numStream, num, ',')) {
            bingoNumbers.push_back(std::stoi(num));
        }

        //parse bingo boards to numberBoardMap
        int counter = 0, numOfBoards = 0, boardIndex = 0, row = 0;
        while(std::getline(inputFile, line)) {
            if (line.empty()) {
                continue;
            }

            boardIndex = counter / 5;
            row = counter % 5;
            std::stringstream ss(line);
            int col = 0;

            if (numOfBoards == boardIndex) {
                boards.push_back(new Board());
                ++numOfBoards;
            }

            while(col < 5 && std::getline(ss, num, ' ')) {
                if (num.empty()) {
                    continue;
                }
                
                int n = std::stoi(num);
                numberBoardMap[n].emplace_back(boardIndex, row, col);
                boards[boardIndex]->unmarkedSum += n;
                ++col;
            }
            ++counter;
        }

        //start playing bingo
        int numOfBoardsWithBingo = 0;
        for(int drawnNumber : bingoNumbers) {
            for(const BoardFinder& bf : numberBoardMap[drawnNumber]) {
                Board* board = boards[bf.boardIndex];
                if (board->hasAlreadyBingoed) {
                    continue;
                }

                ++board->rows[bf.row];
                ++board->cols[bf.col];
                board->unmarkedSum -= drawnNumber;
                
                if (board->isBingo()) {
                    if (numOfBoardsWithBingo == 0) {
                        std::cout << "Answer to day4 part one: " << board->unmarkedSum * drawnNumber << std::endl;
                    } else if (numOfBoardsWithBingo == boards.size() - 1) {
                        std::cout << "Answer to day4 part two: " << board->unmarkedSum * drawnNumber << std::endl;
                        return true;
                    }
                    ++numOfBoardsWithBingo;
                }
            }
        }
    }
    return false;
}

}
}
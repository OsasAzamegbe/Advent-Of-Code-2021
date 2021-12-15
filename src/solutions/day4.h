#pragma once

#include <string>
#include <vector>


namespace Solution
{
namespace Day4
{

bool day4();

struct Board
{
    int rows[5] = {};
    int cols[5] = {};
    int unmarkedSum;
    bool hasAlreadyBingoed;
    
    bool isBingo();
    Board():unmarkedSum(0), hasAlreadyBingoed(false)
    {};
};

struct BoardFinder
{
    int boardIndex;
    int row;
    int col;

    BoardFinder(int bi, int r, int c)
    :boardIndex(bi),
    row(r),
    col(c)
    {
    }
};

}
}
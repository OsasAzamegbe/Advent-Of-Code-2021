#pragma once


namespace Solution
{
namespace Day21
{

struct Die
{
    Die();
    int roll();

    int currentFace;
    int timesRolled;
};

struct Player
{
    Player(int start);
    void move(int numMoves);

    int score;
    int currentSpace;
};

void day21();

}
}
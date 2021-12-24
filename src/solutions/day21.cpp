#include <day21.h>

#include <vector>
#include <string>
#include <iostream>


namespace Solution
{
namespace Day21
{

Die::Die():currentFace(1), timesRolled(0)
{
}

int Die::roll()
{
    int value = 0;
    for(int i = 0; i < 3; ++i) {
        value += currentFace++;
        if (currentFace == 101) {
            currentFace = 1;
        }
    }
    

    timesRolled += 3;
    return value;
}

Player::Player(int start):score(0), currentSpace(start)
{
}

void Player::move(int numMoves)
{
    currentSpace += numMoves;
    currentSpace %= 10;
    if (currentSpace == 0) {
        currentSpace = 10;
    }

    score += currentSpace;
}

void day21()
{
    Player player1(3), player2(5);
    Die die;
    Player* currentPlayer;
    bool isPlayer1Turn = true;

    while(player1.score < 1000 && player2.score < 1000) {
        currentPlayer = isPlayer1Turn ? &player1 : &player2;
        currentPlayer->move(die.roll());

        isPlayer1Turn = !isPlayer1Turn;
    }

    // std::cout << "player1 scored: " << player1.score << " Player2 scored: " << player2.score << std::endl;
    // std::cout << "rolled: " << die.timesRolled << std::endl;

    std::cout << "Answer to day 21 part one: " << (player1.score >= 1000 ? player2.score : player1.score) * die.timesRolled << std::endl;
}

}
}
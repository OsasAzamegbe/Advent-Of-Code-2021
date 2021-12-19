#include <day10.h>

#include <fstream>
#include <iostream>
#include <string>
#include <stack>


namespace Solution
{
namespace Day10
{

void day10()
{
    std::ifstream inputFile("testfiles/day10test.txt");
    std::string line;
    std::stack<char> chunkStack;
    int totalSyntaxScore = 0;
    bool isCorrupted;
    while(std::getline(inputFile, line)) {
        isCorrupted = false;
        for(char bracket : line) {
            if (isCorrupted) {
                break;
            }

            switch (bracket) {
                case '(':
                case '{':
                case '[':
                case '<':
                    chunkStack.push(bracket);
                    break;
                case ')':
                    if (chunkStack.top() == '(') {
                        chunkStack.pop();
                    } else {
                        totalSyntaxScore += 3;
                        isCorrupted = true;
                    }
                    break;
                case ']':
                    if (chunkStack.top() == '[') {
                        chunkStack.pop();
                    } else {
                        totalSyntaxScore += 57;
                        isCorrupted = true;
                    }
                    break;
                case '}':
                    if (chunkStack.top() == '{') {
                        chunkStack.pop();
                    } else {
                        totalSyntaxScore += 1197;
                        isCorrupted = true;
                    }
                    break;
                case '>':
                    if (chunkStack.top() == '<') {
                        chunkStack.pop();
                    } else {
                        totalSyntaxScore += 25137;
                        isCorrupted = true;
                    }
                    break;
                default:
                    std::cout << "invalid bracket" << std::endl;
            }
        }
    }

    std::cout << "Answer to day 10 part one: " << totalSyntaxScore << std::endl;
}

}
}
#include <day10.h>

#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>


namespace Solution
{
namespace Day10
{

void day10()
{
    std::ifstream inputFile("testfiles/day10test.txt");
    std::string line;
    int totalSyntaxScore = 0;
    bool isCorrupted;
    std::vector<long long> completionScores;
    while(std::getline(inputFile, line)) {
        std::stack<char> chunkStack;
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

        if(!isCorrupted) {
            long long completionScore = 0;
            while(!chunkStack.empty()) {
                switch(chunkStack.top()) {
                    case '(':
                        completionScore = completionScore * 5 + 1;
                        break;
                    case '{':
                        completionScore = completionScore * 5 + 3;
                        break;
                    case '[':
                        completionScore = completionScore * 5 + 2;
                        break;
                    case '<':
                        completionScore = completionScore * 5 + 4;
                        break;
                    default:
                        std::cout << "not an opening bracket" << std::endl;
                }

                chunkStack.pop();

            }

            if (completionScore) {
                completionScores.push_back(completionScore);
            }
        }
    }

    std::sort(completionScores.begin(), completionScores.end());
    int middleIndex = completionScores.size() / 2;

    std::cout << "Answer to day 10 part one: " << totalSyntaxScore << std::endl;
    std::cout << "Answer to day 10 part two: " << completionScores[middleIndex] << std::endl;
}

}
}
#include <day1.h>


namespace Solution
{
namespace Day1
{

void day1()
{
    std::vector<int> inputVector;
    Day1::readInput(inputVector, "day1test.txt");
    std::cout << "Answer: " << Day1::solve(inputVector) << std::endl;
}

void readInput(std::vector<int>& inputVector, const char* filename) 
{
    std::string num;
    std::ifstream inputFile(filename);

    while(std::getline(inputFile, num)) {
        inputVector.push_back(std::stoi(num));
    }

    inputFile.close();

}

int solve(const std::vector<int>& inputVector)
{
    int answer = 0;
    for (int i = 1; i < inputVector.size(); ++i) {
        if (inputVector[i] > inputVector[i-1]) {
            ++answer;
        }
    }

    return answer;
}

}

}
#include <day2.h>

#include <sstream>


namespace Solution
{
namespace Day2
{

void day2()
{
    std::cout << "Answer to day2 part one: " << Day2::solve() << std::endl;
}


int solve()
{
    int x = 0, y = 0, num = 0;
    std::string line, command, value;
    std::ifstream inputFile("day2test.txt");

    while(std::getline(inputFile, line)) {
        //parse the input
        std::stringstream ss(line);
        std::getline(ss, command, ' ');
        std::getline(ss, value, ' ');
        num = std::stoi(value);

        if (command == "forward") {
            x += num;
        } else if (command == "up") {
            y -= num;
        } else {
            y += num;
        }
    }

    inputFile.close();
    return x * y;
}

}
}
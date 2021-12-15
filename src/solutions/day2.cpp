#include <day2.h>

#include <sstream>


namespace Solution
{
namespace Day2
{

void day2()
{
    int x = 0, y = 0, y2 = 0, aim = 0, num = 0;
    std::string line, command, value;
    std::ifstream inputFile("testfiles/day2test.txt");

    while(std::getline(inputFile, line)) {
        //parse the input
        std::stringstream ss(line);
        std::getline(ss, command, ' ');
        std::getline(ss, value, ' ');
        num = std::stoi(value);

        if (command == "forward") {
            x += num;
            y2 += aim * num;
        } else if (command == "up") {
            y -= num;
            aim -= num;
        } else {
            y += num;
            aim += num;
        }
    }

    inputFile.close();
    std::cout << "Answer to day2 part one: " << x * y << std::endl;
    std::cout << "Answer to day2 part two: " << x * y2 << std::endl;
}


}
}
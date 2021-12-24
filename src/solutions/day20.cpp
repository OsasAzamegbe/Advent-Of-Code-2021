#include <day20.h>

#include <fstream>
#include <iostream>
#include <util.h>


namespace Solution
{
namespace Day20
{

void day20()
{
    std::ifstream inputFile("testfiles/day20test.txt");
    std::string line;
    std::string imageEnhancementAlgo;
    std::vector<std::vector<char>> image;

    std::getline(inputFile, imageEnhancementAlgo);
    while(std::getline(inputFile, line)) {
        if(line.empty()) {
            continue;
        }
        image.push_back(std::vector<char>());
        for(char pixel : line) {
            image.back().push_back(pixel);
        }
    }
    countLightPixel(image);
    char fillPixel = '.';

    std::vector<std::vector<char>> secondImage(image.size() + 4, std::vector<char>(image[0].size() + 4));
    fillPixel = enhanceImage(secondImage, image, imageEnhancementAlgo, fillPixel);

    std::cout << fillPixel << std::endl;
    countLightPixel(secondImage);

    std::vector<std::vector<char>> thirdImage(secondImage.size() + 4, std::vector<char>(secondImage[0].size() + 4));
    enhanceImage(thirdImage, secondImage, imageEnhancementAlgo, fillPixel);

    std::cout << "Answer to day 20 part one: " << countLightPixel(thirdImage) << std::endl;
    std::cout << "Answer to day 20 part two: " << "placeholder" << std::endl;

}

char enhanceImage(
    std::vector<std::vector<char>>& resultImage, const std::vector<std::vector<char>>& inputImage,
    const std::string& imageEnhancementAlgo, char fillPixel)
{
    int rows = inputImage.size(), cols = inputImage[0].size();
    for (int row = -2; row < rows + 2; ++row) {
        for (int col = -2; col < cols + 2; ++col) {
            resultImage[row + 2][col + 2] = imageEnhancementAlgo[getEnhancementIndex(inputImage, row, col, fillPixel)];
        }
    }
    return fillPixel == '.' ? imageEnhancementAlgo[0] : imageEnhancementAlgo.back();
}

int getEnhancementIndex(const std::vector<std::vector<char>>& inputImage, int row, int col, char fillPixel)
{
    std::string binary = "";
    for(int i = row - 1; i < row + 2; ++i) {
        for (int j = col - 1; j < col + 2; ++j) {
            if (getPixel(inputImage, i, j, fillPixel) == '.') {
                binary.push_back('0');
            } else {
                binary.push_back('1');
            }
        }
    }

    return std::stoi(binary, nullptr, 2);
}

char getPixel(const std::vector<std::vector<char>>& inputImage, int row, int col, char fillPixel)
{
    if(row >= 0 && row < inputImage.size() && col >= 0 && col < inputImage[0].size()) {
        return inputImage[row][col];
    }

    return fillPixel;
}

int countLightPixel(const std::vector<std::vector<char>>& image)
{
    int numLightPixels = 0;
    for(int i = 0; i < image.size(); ++i) {
        std::cout << std::endl;
        for (int j = 0; j < image[0].size(); ++j) {
            std::cout << image[i][j];
            if(image[i][j] == '#') {
                ++numLightPixels;
            }
        }
    }
    std::cout << '\n' << std::endl;

    return numLightPixels;
}


}
}
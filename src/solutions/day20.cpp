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
    std::getline(inputFile, line); // for empty second line

    while(std::getline(inputFile, line)) {
        image.push_back(std::vector<char>());
        for(char pixel : line) {
            image.back().push_back(pixel);
        }
    }
    char fillPixel = '.';

    std::cout << "Answer to day 20 part one: " << enhanceImage(image, imageEnhancementAlgo, fillPixel, 2) << std::endl;
    std::cout << "Answer to day 20 part two: " << enhanceImage(image, imageEnhancementAlgo, fillPixel, 48) << std::endl;

}

int enhanceImage(
    std::vector<std::vector<char>>& image,
    const std::string& imageEnhancementAlgo, char fillPixel, int numOfEnhancements)
{
    while (numOfEnhancements > 0) {
        std::vector<std::vector<char>> resultImage(image.size() + 4, std::vector<char>(image[0].size() + 4));
        fillPixel = enhanceImage(resultImage, image, imageEnhancementAlgo, fillPixel);
        image = resultImage;

        --numOfEnhancements;
    }
    return countLightPixel(image);
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
    std::string binary;
    for(int i = row - 1; i < row + 2; ++i) {
        for (int j = col - 1; j < col + 2; ++j) {
            binary.push_back(getPixel(inputImage, i, j, fillPixel) == '.' ? '0' : '1');
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
        for (int j = 0; j < image[0].size(); ++j) {
            if(image[i][j] == '#') {
                ++numLightPixels;
            }
        }
    }

    return numLightPixels;
}


}
}
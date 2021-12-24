#pragma once

#include <vector>
#include <string>


namespace Solution
{
namespace Day20
{

void day20();
char enhanceImage(
    std::vector<std::vector<char>>& resultImage, const std::vector<std::vector<char>>& inputImage,
    const std::string& imageEnhancementAlgo, char fillPixel);
int enhanceImage(
    std::vector<std::vector<char>>& image,
    const std::string& imageEnhancementAlgo, char fillPixel, int numOfEnhancements);
int getEnhancementIndex(const std::vector<std::vector<char>>& inputImage, int row, int col, char fillPixel);
char getPixel(const std::vector<std::vector<char>>& inputImage, int row, int col, char fillPixel);
int countLightPixel(const std::vector<std::vector<char>>& image);

}
}
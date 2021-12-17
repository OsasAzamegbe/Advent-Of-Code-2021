#pragma once

#include <string>
#include <vector>


namespace Solution
{
namespace Day8
{

void day8();
bool isUniqueDigit(const std::string& digit);
void decodeUniqueSignals(int* segmentMap, const std::vector<std::string>& uniqueSignals);
int parseOutputValuesToDecimal(int* NUMBER_VALUES, const std::vector<std::string>& uniqueSignals, const std::vector<std::string>& outputValues);
int index(char letter);

}
}
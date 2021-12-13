#pragma once
#include <string>
#include <iostream>

void print(const std::string& message);

template <typename Iterator>
void print(Iterator begin, Iterator end)
{
    std::cout << "[";
    for (Iterator it = begin; it != end; ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "]" << std::endl;
}
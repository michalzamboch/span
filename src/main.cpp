#include <iostream>
#include <span>
#include <vector>
#include <array>
#include "custom_iterator.h"

void printSpan(std::span<int> numbers)
{
    if (numbers.extent == std::dynamic_extent)
    {
        std::cout << "dynamic" << std::endl;
    }
    else
    {
        std::cout << "static" << std::endl;
    }

    for (const auto& num : numbers) {
        std::cout << num << " ";
    } 
    std::cout << std::endl;
}

void printString(std::span<char> numbers)
{
    for (const auto& num : numbers) {
        std::cout << num;
    } 
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    int array[5] = {1,2,3,4,5};
    printSpan(array);

    std::vector<int> intVector {1,2,3,4,5,6,7,8,9};
    printSpan(intVector);

    std::array<int, 4> intArray {4,3,2,1};
    printSpan(intArray);

    std::string message {"Hello world"};
    printString(message);

    std::vector<char> chars {'H', 'e', 'l', 'l', 'o'};
    printString(chars);

    return 0;
}

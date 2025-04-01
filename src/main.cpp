#include <iostream>
#include <span>
#include <vector>
#include <array>
#include "custom_iterator.h"

void printString(std::span<char> numbers)
{
    for (const auto& num : numbers) {
        std::cout << num;
    } 
    std::cout << std::endl;
}

void printSpan(std::span<int> numbers)
{
    for (const auto& num : numbers) {
        std::cout << num << " ";
    } 
    std::cout << std::endl;
}

void setSpan(std::span<int> numbers, int value)
{
    for (auto& num : numbers) {
        num = value;
    } 
}

void setSpanValue(std::span<int> numbers, int value, int pos)
{
    if (numbers.size() <= pos)
    {
        std::cout << "Position is too high!" << std::endl;
        return;
    }

    numbers[pos] = value;
}

int main(int argc, char** argv)
{
    int array[5] = {1,2,3,4,5};
    setSpanValue(array, 100, 10);
    setSpanValue(array, 100, 1);
    printSpan(array);

    std::vector<int> intVector {1,2,3,4,5,6,7,8,9};
    printSpan(intVector);
    setSpan(intVector, 1);
    setSpanValue(intVector, 100, 0);
    printSpan(intVector);

    std::array<int, 4> intArray {4,3,2,1};
    printSpan(intArray);

    std::string message {"Hello world"};
    printString(message);

    std::vector<char> chars {'H', 'e', 'l', 'l', 'o'};
    printString(chars);

    return 0;
}

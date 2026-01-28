#include "../../../Array.hpp"
#include <iostream>

int main(void)
{
    Array<int, 7>   array;

    std::cout << "Array: " << array << std::endl;
    
    // Fill array
    for (std::size_t i = 0; i < array.size(); i++) {
        array[i] = i * 10;
    }

    std::cout << "Array: " << array << std::endl;
    std::cout << "Size: " << array.size() << std::endl;

    // Test convert and forEach
    array
        .convert<int>([](const int& v) { return v * (3); })
        .forEach([](const int& v) { std::cout << v << " "; });
    std::cout << std::endl;

    // Test out of range
    try {
        array[10] = 999;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

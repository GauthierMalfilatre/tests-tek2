#include "../../../Array.hpp"
#include <iostream>

int main(void)
{
    Array<int, 5>   array;

    // Fill array
    for (std::size_t i = 0; i < array.size(); i++) {
        array[i] = i * 10;
    }

    std::cout << "Array: " << array << std::endl;
    std::cout << "Size: " << array.size() << std::endl;

    // Test convert and forEach
    array
        .convert<double>([](const int& v) { return v * 1.5; })
        .forEach([](const double& v) { std::cout << v << " "; });
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

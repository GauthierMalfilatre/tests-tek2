#include "../../../Algorithm.hpp"
#include "../../../myInt.hpp"
#include <algorithm>
#include <iostream>

int main(void)
{
    // Test with double values
    double x = 3.14;
    double y = 2.71;

    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
    std::cout << "clamp(3.0, x, y) = " << ::clamp(3.0, x, y) << std::endl;

    // Test with negative values
    int a = -10;
    int b = -50;
    
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << "clamp(-30, a, b) = " << ::clamp(-30, b, a) << std::endl;
    // std::cout << "clamp(-30, a, b) = " << std::clamp(-30, a, b) << std::endl;

    return 0;
}

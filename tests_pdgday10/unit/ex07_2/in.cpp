#include "../../../Matrix.hpp"
#include <iostream>

int main(void)
{
    // Test 2x2 matrix multiplication
    Matrix<2, 2> mat1;
    Matrix<2, 2> mat2;

    mat1(0, 0) = 1; mat1(0, 1) = 2;
    mat1(1, 0) = 3; mat1(1, 1) = 4;
    std::cout << "Matrix 1: " << mat1 << std::endl;

    mat2(0, 0) = 2; mat2(0, 1) = 0;
    mat2(1, 0) = 1; mat2(1, 1) = 2;
    std::cout << "Matrix 2: " << mat2 << std::endl;

    Matrix<2, 2> result = mat1 * mat2;
    std::cout << "Result: " << result << std::endl;

    // Test out of range
    try {
        mat1(5, 5) = 42;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

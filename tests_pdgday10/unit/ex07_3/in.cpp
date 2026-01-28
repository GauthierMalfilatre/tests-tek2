#include "../../../Matrix.hpp"
#include <iostream>

int main(void)
{
    // Test 3x2 and 2x3 multiplication
    Matrix<3, 2> mat1;
    Matrix<2, 3> mat2;

    mat1(0, 0) = 1; mat1(0, 1) = 2;
    mat1(1, 0) = 3; mat1(1, 1) = 4;
    mat1(2, 0) = 5; mat1(2, 1) = 6;
    std::cout << "Matrix 3x2: " << mat1 << std::endl;

    mat2(0, 0) = 1; mat2(0, 1) = 0; mat2(0, 2) = 1;
    mat2(1, 0) = 0; mat2(1, 1) = 1; mat2(1, 2) = 0;
    std::cout << "Matrix 2x3: " << mat2 << std::endl;

    Matrix<3, 3> result = mat1 * mat2;
    std::cout << "Result 3x3: " << result << std::endl;

    // Test identity matrix
    Matrix<3, 3> identity;
    identity(0, 0) = identity(1, 1) = identity(2, 2) = 1.0;
    Matrix<3, 3> test = result * identity;
    std::cout << "Result * Identity: " << test << std::endl;

    return 0;
}

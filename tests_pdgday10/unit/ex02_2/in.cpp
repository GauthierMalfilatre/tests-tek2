#include "../../../Stack.hpp"
#include <iostream>

int main(void)
{
    Stack stack;

    // Test basic operations
    stack.push(10.0);
    stack.push(20.0);
    stack.add();
    std::cout << "After 10 + 20: " << stack.top() << std::endl;

    stack.push(5.0);
    stack.sub();
    std::cout << "After 30 - 5: " << stack.top() << std::endl;

    stack.push(3.0);
    stack.mul();
    std::cout << "After 25 * 3: " << stack.top() << std::endl;

    // Test error on empty stack
    try {
        Stack empty;
        empty.add();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

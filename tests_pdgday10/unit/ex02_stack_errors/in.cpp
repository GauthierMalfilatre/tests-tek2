#include "../../../Stack.hpp"
#include <iostream>

static void stack_top(const Stack& stack) {
    std::cout << "stack.top() = ";
    try {
        std::cout << stack.top() << std::endl;
    } catch (Stack::Error& e) {
        std::cout << "Stack::Error::what(): " << e.what() << std::endl;
    }
}

static void stack_pop(Stack& stack) {
    std::cout << "stack.pop()" << std::endl;
    try {
        stack.pop();
    } catch (Stack::Error& e) {
        std::cout << "Stack::Error::what(): " << e.what() << std::endl;
    }
}

static void stack_add(Stack& stack) {
    std::cout << "stack.add()" << std::endl;
    try {
        stack.add();
    } catch (Stack::Error& e) {
        std::cout << "Stack::Error::what(): " << e.what() << std::endl;
    }
}

static void stack_sub(Stack& stack) {
    std::cout << "stack.sub()" << std::endl;
    try {
        stack.sub();
    } catch (Stack::Error& e) {
        std::cout << "Stack::Error::what(): " << e.what() << std::endl;
    }
}

static void stack_mul(Stack& stack) {
    std::cout << "stack.mul()" << std::endl;
    try {
        stack.mul();
    } catch (Stack::Error& e) {
        std::cout << "Stack::Error::what(): " << e.what() << std::endl;
    }
}

static void stack_div(Stack& stack) {
    std::cout << "stack.div()" << std::endl;
    try {
        stack.div();
    } catch (Stack::Error& e) {
        std::cout << "Stack::Error::what(): " << e.what() << std::endl;
    }
}

static void stack_push(Stack& stack, double d) {
    std::cout << "stack.push(" << d << ")" << std::endl;
    stack.push(d);
}

int main(void)
{
    Stack stack;

    stack_top(stack);
    stack_pop(stack);
    stack_push(stack, 5.6);
    stack_top(stack);
    stack_add(stack);
    stack_top(stack);
    stack_sub(stack);
    stack_top(stack);
    stack_mul(stack);
    stack_top(stack);
    stack_div(stack);
    stack_top(stack);
    stack_push(stack, 1.9);
    stack_top(stack);
    stack_push(stack, 9);
    stack_top(stack);
    stack_push(stack, 2.2);
    stack_top(stack);
    stack_push(stack, 6);
    stack_top(stack);
    stack_add(stack);
    stack_top(stack);
    stack_sub(stack);
    stack_top(stack);
    stack_mul(stack);
    stack_top(stack);
    stack_div(stack);
    stack_top(stack);
    stack_pop(stack);
    stack_pop(stack);
    return 0;
}

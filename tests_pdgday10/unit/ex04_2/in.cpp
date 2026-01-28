#include "../../../Stack.hpp"
#include "../../../Command.hpp"
#include <iostream>

int main(void)
{
    Command command;
    Stack stack;
    int counter = 0;

    // Register commands
    command.registerCommand("push_10", [&stack]() { stack.push(10.0); });
    command.registerCommand("push_5", [&stack]() { stack.push(5.0); });
    command.registerCommand("show", [&stack]() { std::cout << "Stack top: " << stack.top() << std::endl; });
    command.registerCommand("multiply", [&stack]() { stack.mul(); });
    command.registerCommand("increment", [&counter]() { counter++; std::cout << "Counter: " << counter << std::endl; });

    // Execute commands
    try {
        command.executeCommand("push_10");
        command.executeCommand("push_5");
        command.executeCommand("multiply");
        command.executeCommand("show");
        command.executeCommand("increment");
        command.executeCommand("increment");
        command.executeCommand("unknown");
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

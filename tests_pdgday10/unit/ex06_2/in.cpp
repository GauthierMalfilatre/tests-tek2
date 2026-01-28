#include "../../../Shell.hpp"
#include "../../../Stack.hpp"
#include "../../../Command.hpp"
#include <iostream>

int main(void)
{
    Shell shell(std::cin);
    Stack stack;
    Command command;

    command.registerCommand("push", [&shell, &stack]() { stack.push(shell.extract<double>()); });
    command.registerCommand("display", [&stack]() { std::cout << stack.top() << std::endl; });
    command.registerCommand("add", [&stack]() { stack.add(); });
    command.registerCommand("sub", [&stack]() { stack.sub(); });
    command.registerCommand("mul", [&stack]() { stack.mul(); });
    command.registerCommand("div", [&stack]() { stack.div(); });

    while (true) {
        try {
            std::cout << "> " << std::flush;
            shell.next();
            command.executeCommand(shell.extract<std::string>());
        }
        catch (const Shell::Error& e) {
            std::cout << e.what() << std::endl;
            break;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
    return 0;
}

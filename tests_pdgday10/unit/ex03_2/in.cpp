#include "../../../UniquePointer.hpp"
#include <iostream>

class Test
{
private:
    std::string _name;

public:
    Test(std::string name) : _name(name) { 
        std::cout << _name << " created" << std::endl; 
    }
    ~Test() { 
        std::cout << _name << " destroyed" << std::endl; 
    }

    void display() const { 
        std::cout << "Test: " << _name << std::endl; 
    }
};

int main(void)
{
    UniquePointer<Test> ptr1(new Test("First"));
    ptr1->display();
    
    UniquePointer<Test> ptr2;
    ptr2 = new Test("Second");
    ptr2.get()->display();

    ptr1.reset();
    std::cout << "After reset" << std::endl;

    return 0;
}

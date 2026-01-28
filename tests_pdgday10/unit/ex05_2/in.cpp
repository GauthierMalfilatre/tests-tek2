#include "../../../SharedPointer.hpp"
#include <iostream>

class Resource
{
private:
    int _value;

public:
    Resource(int val) : _value(val) { 
        std::cout << "Resource(" << _value << ") created" << std::endl; 
    }
    ~Resource() { 
        std::cout << "Resource(" << _value << ") destroyed" << std::endl; 
    }

    void show() const { 
        std::cout << "Value: " << _value << std::endl; 
    }
    void setValue(int val) { _value = val; }
};

int main(void)
{
    SharedPointer<Resource> ptr1(new Resource(100));
    ptr1->show();
    
    {
        SharedPointer<Resource> ptr2(ptr1);
        SharedPointer<Resource> ptr3(ptr1);
        ptr2->show();
        ptr3->setValue(200);
        ptr1->show();
        std::cout << "Inner scope end" << std::endl;
    }
    
    std::cout << "After scope" << std::endl;
    ptr1.reset();
    std::cout << "After reset" << std::endl;

    return 0;
}

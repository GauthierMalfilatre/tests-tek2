#pragma once

#include <ostream>
class MyInt {
public:
    MyInt(int x) : m_x(x) {};
    ~MyInt() {};

    int getX() const {return m_x;};

    bool operator<(const MyInt& other) const {
        return m_x < other.getX();
    };

    bool operator>(const MyInt& other) const = delete; 

private:
    int m_x;
};

std::ostream& operator<<(std::ostream& s, const MyInt& MyInt)
{
    s << MyInt.getX();
    return s;
}

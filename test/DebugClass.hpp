#pragma once

#include <iostream>
#include <string>


class DebugClass
{

public:

DebugClass()
{
    std::cout << "Constructor called." << std::endl;
}

DebugClass(const DebugClass& other)
{
    std::cout << "Copy constructor called." << std::endl;
}

DebugClass(DebugClass&& other)
{
    std::cout << "Move constructor called." << std::endl;
}

~DebugClass()
{
    std::cout << "Destructor called." << std::endl;
}

DebugClass& operator=(const DebugClass& other)
{
    std::cout << "Copy assignment called." << std::endl;
    return *this;
}

DebugClass& operator=(DebugClass&& other)
{
    std::cout << "Move assignment called." << std::endl;
    return *this;
}

void hello() const
{
    std::cout << "hello " << this << std::endl; 
}

private:

    std::string id;

};

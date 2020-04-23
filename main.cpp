#include <iostream>

#include "VariantTest.hpp"


using namespace ZigZag;

int main()
{
    ZigZag::Variant var;
    std::cout << var.isNull() << std::endl;

    var.set(20);
    std::cout << var.get<int>() << std::endl;

    var.get<int>() = 50;
    std::cout << var.get<int>() << std::endl;

    var.set<std::string>(std::string("test"));
    std::cout << var.get<std::string>() << std::endl;

    std::cout << var.get<int>() << std::endl;


    std::cout << sizeof(VariantTypeAtIndex<1>::type) << std::endl;
    std::cout << sizeof(VariantTypeAtIndex<2>::type) << std::endl;
    std::cout << sizeof(VariantTypeAtIndex<3>::type) << std::endl;
    //std::cout << sizeof(VariantTypeAtIndex<3>::type) << std::endl;
    //std::cout << sizeof(VariantIndex<1>::type) << std::endl;
    

    return 0;
}
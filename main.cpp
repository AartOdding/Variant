#include <iostream>

#include "VariantTest.hpp"

#include "DebugClass.hpp"


using namespace ZigZag;


template<> 
struct VariantTypeAtIndex<6>
{
    using type = DebugClass;
};

template<> 
struct VariantIndexForType<DebugClass>
{
    static constexpr uintPtr index = 6;
};

VariantHelperMethods variantDebugClassHelpers
{
    6,
    [](void*&, void*){},
    [](void* ptr){ delete static_cast<DebugClass*>(ptr); }
};



int main()
{
    ZigZag::Variant var;
    std::cout << var.isNull() << std::endl;

    DebugClass dbg;
    Variant dbgVar;
    dbgVar.set(dbg);
    dbg.hello();

    DebugClass dbg2;
    dbgVar.set(std::move(dbg2));


    var.set(20);
    std::cout << var.get<int>() << std::endl;

    var.get<int>() = 50;
    std::cout << var.get<int>() << std::endl;

    var.set<std::string>("test");
    std::cout << var.get<std::string>() << std::endl;

    var.set<int>(40);
    std::cout << var.get<int>() << std::endl;


    std::cout << sizeof(VariantTypeAtIndex<1>::type) << std::endl;
    std::cout << sizeof(VariantTypeAtIndex<2>::type) << std::endl;
    std::cout << sizeof(VariantTypeAtIndex<3>::type) << std::endl;
    //std::cout << sizeof(VariantTypeAtIndex<3>::type) << std::endl;
    //std::cout << sizeof(VariantIndex<1>::type) << std::endl;
    

    return 0;
}
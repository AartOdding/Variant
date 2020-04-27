#include <iostream>

#include "VariantTest.hpp"

#include "DebugClass.hpp"


using namespace EasyVariant;


template<> 
struct VariantTypeAtIndex<6>
{
    using type = DebugClass;
};

template<> 
struct VariantIndexForType<DebugClass>
{
    static constexpr uintptr_t index = 6;
};

const inline VariantTypeImplementation variantDebugClassHelpers
{
    6,
    [](void*& ptr, void* other){ ptr = new DebugClass(*static_cast<DebugClass*>(other)); },
    [](void* ptr){ delete static_cast<DebugClass*>(ptr); }
};


int main()
{
    Variant v1;
    v1 = DebugClass();
    v1.clear();
    
    std::cout << "baaia" << std::endl;
    /*
    EasyVariant::Variant var;
    std::cout << var.isNull() << std::endl;

    DebugClass dbg;
    Variant dbgVar;
    dbgVar.set(dbg);
    dbg.hello();

    DebugClass dbg2;
    dbgVar.set(std::move(dbg2));
    Variant debug(dbgVar);
    debug.set(20);
    dbgVar.set(45);


    var.set(20);
    std::cout << var.get<int>() << std::endl;

    var.get<int>() = 50;
    std::cout << var.get<int>() << std::endl;

    var.set<std::string>("test");
    std::cout << var.get<std::string>() << std::endl;

    var.set<int>(40);
    std::cout << var.get<int>() << std::endl;
    */


    

    return 0;
}
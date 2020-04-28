#include <iostream>

#include "Variant.hpp"
#include "VariantRegisterType.hpp"

#include "DebugClass.hpp"


using namespace EasyVariant;


VARIANT_REGISTER_TYPE(DebugClass, 6)
VARIANT_REGISTER_TYPE(std::string, 2000)
VARIANT_REGISTER_TYPE(int, 1)



int main()
{
    Variant v1;
    v1 = DebugClass();
    v1.clear();

    Variant v2;
    v2 = 23089123;
    v2 = std::string("haai");

    std::cout << "baai" << std::endl;
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
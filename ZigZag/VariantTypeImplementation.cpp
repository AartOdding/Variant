#include <ZigZag/VariantTypeImplementation.hpp>


using namespace ZigZag;


std::unordered_map<uintptr_t, VariantTypeImplementation*>* VariantTypeImplementation::getRegisteredTypes()
{
    static std::unordered_map<uintptr_t, VariantTypeImplementation*> registeredVariantTypes;
    return &registeredVariantTypes;
}


VariantTypeImplementation::VariantTypeImplementation(uintptr_t typeIndex, CopyFn&& copyFn, DestructFn&& destructFn, EqualFn&& equalFn)
    : copy(std::move(copyFn)),
      destruct(std::move(destructFn)),
      equal(std::move(equalFn))
{
    // When typeIndex was already in use it is overriden, this is desired behaviour.
    // Because VariantTypeImplementation objects can be declared as inline variables in 
    // header files.
    getRegisteredTypes()->insert_or_assign(typeIndex, this);
}

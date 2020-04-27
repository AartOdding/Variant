#include "VariantTypeImplementation.hpp"


using namespace EasyVariant;


std::unordered_map<uintptr_t, VariantTypeImplementation*>* VariantTypeImplementation::getRegisteredTypes()
{
    static std::unordered_map<uintptr_t, VariantTypeImplementation*> registeredVariantTypes;
    return &registeredVariantTypes;
}


VariantTypeImplementation::VariantTypeImplementation(uintptr_t typeIndex, CopyFn&& copyFn, DestructFn&& destructFn)
    : copy(std::move(copyFn)),
      destruct(std::move(destructFn))
{
    // When typeIndex was already in use it is overriden, this is desired behaviour.
    // Because VariantTypeImplementation objects can be declared as inline variables in 
    // header files.
    getRegisteredTypes()->insert_or_assign(typeIndex, this);
}

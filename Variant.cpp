#include "Variant.hpp"


namespace ZigZag
{


VariantHelperMethods::VariantHelperMethods(uintPtr typeIndex, Constructor&& constructor, Destructor&& destructor)
    : construct(std::move(constructor)),
      destruct(std::move(destructor))
{
    // When typeIndex was already in use it is overriden, this is desired behaviour.
    Variant::registeredVariantTypes[typeIndex] = this;
}

std::unordered_map<uintPtr, VariantHelperMethods*> Variant::registeredVariantTypes;


bool Variant::isNull() const
{
    return m_typeIndex == 0;
}


}


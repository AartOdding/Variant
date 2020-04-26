#include "Variant.hpp"

#include <string>


namespace ZigZag
{



std::unordered_map<uintPtr, VariantHelperMethods*>* Variant::getRegisteredTypes()
{
    static std::unordered_map<uintPtr, VariantHelperMethods*> registeredVariantTypes;
    return &registeredVariantTypes;
}


VariantHelperMethods::VariantHelperMethods(uintPtr typeIndex, Constructor&& constructor, Destructor&& destructor)
    : construct(std::move(constructor)),
      destruct(std::move(destructor))
{
    // When typeIndex was already in use it is overriden, this is desired behaviour.
    Variant::getRegisteredTypes()->insert_or_assign(typeIndex, this);
}




void Variant::destruct()
{
    if (m_typeIndex != 0)
    {
        auto it = getRegisteredTypes()->find(m_typeIndex);

        if (it != getRegisteredTypes()->end())
        {
            it->second->destruct(m_data);
            m_typeIndex = 0;
        }
        else
        {
            throw std::runtime_error("No VariantHelperMethods available for Variant with type: " + std::to_string(m_typeIndex));
        }
    }
}


bool Variant::isNull() const
{
    return m_typeIndex == 0;
}


}

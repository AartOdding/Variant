#include <ZigZag/Variant.hpp>

#include <string>


using namespace ZigZag;



Variant::Variant(const Variant& other)
    : m_typeIndex(other.m_typeIndex)
{
    if (m_typeIndex != 0)
    {
        auto it = VariantTypeImplementation::getRegisteredTypes()->find(m_typeIndex);

        if (it != VariantTypeImplementation::getRegisteredTypes()->end())
        {
            it->second->copy(m_data, other.m_data);
        }
        else
        {
            throw std::runtime_error("No VariantTypeImplementation available for Variant with type: " + std::to_string(m_typeIndex));
        }
    }
}


Variant::Variant(Variant&& other)
    : m_data(other.m_data),
      m_typeIndex(other.m_typeIndex)
{
    other.m_data = nullptr;
    other.m_typeIndex = 0;
}


Variant::~Variant()
{
    destruct();
}


Variant& Variant::operator=(const Variant& other)
{
    m_typeIndex = other.m_typeIndex;

    if (m_typeIndex != 0)
    {
        auto it = VariantTypeImplementation::getRegisteredTypes()->find(m_typeIndex);

        if (it != VariantTypeImplementation::getRegisteredTypes()->end())
        {
            it->second->copy(m_data, other.m_data);
        }
        else
        {
            throw std::runtime_error("No VariantTypeImplementation available for Variant with type: " + std::to_string(m_typeIndex));
        }
    }
    return *this;
}


Variant& Variant::operator=(Variant&& other)
{
    m_data = other.m_data;
    m_typeIndex = other.m_typeIndex;
    other.m_data = nullptr;
    other.m_typeIndex = 0;
    return *this;
}


void Variant::clear()
{
    destruct();
}


bool Variant::isNull() const
{
    return m_typeIndex == 0;
}


void Variant::destruct()
{
    if (m_typeIndex != 0)
    {
        auto it = VariantTypeImplementation::getRegisteredTypes()->find(m_typeIndex);

        if (it != VariantTypeImplementation::getRegisteredTypes()->end())
        {
            it->second->destruct(m_data);
            m_typeIndex = 0;
        }
        else
        {
            throw std::runtime_error("No VariantTypeImplementation available for Variant with type: " + std::to_string(m_typeIndex));
        }
    }
}


bool Variant::operator==(const Variant& other) const
{
    if (m_typeIndex == other.m_typeIndex)
    {
        auto it = VariantTypeImplementation::getRegisteredTypes()->find(m_typeIndex);
        
        if (it != VariantTypeImplementation::getRegisteredTypes()->end())
        {
            return it->second->equal(m_data, other.m_data);
        }
        else
        {
            throw std::runtime_error("No VariantTypeImplementation available for Variant with type: " + std::to_string(m_typeIndex));
        }
    }
    return false;
}


bool Variant::operator!=(const Variant& other) const
{
    return !(operator==(other));
}

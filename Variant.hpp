#pragma once

#include <cstdint>
#include <functional>
#include <stdexcept>
#include <type_traits>
#include <unordered_map>


namespace ZigZag
{

using uintPtr = std::conditional<sizeof(void*) == 4, uint32_t, uint64_t>::type;



template<int index>
struct VariantTypeAtIndex
{
    using type = void;
};


template<typename T>
struct VariantIndexForType
{
    static constexpr uintPtr index = 0;
};


struct VariantHelperMethods
{
    using Constructor = std::function<void(void*&, void*)>;
    using Destructor = std::function<void(void*)>;

    VariantHelperMethods(uintPtr typeIndex, Constructor&& constructor, Destructor&& destructor);

    const Constructor construct;
    const Destructor destruct;
};


class Variant
{
public:

    // Will destroy the value currently contained in the Variant, and reset its value to null.
    void clear();

    bool isNull() const;


    template<typename T> 
    T& get();

    template<typename T>
    const T& get() const;

    template<typename T>
    void set(const T& value);

    template<typename T>
    void set(T&& value);

private:

    void destruct();

    void* m_data = nullptr;
    uintPtr m_typeIndex = 0;


    friend class VariantHelperMethods;

    static std::unordered_map<uintPtr, VariantHelperMethods*>* getRegisteredTypes();

};

}


#include "Variant.inl"

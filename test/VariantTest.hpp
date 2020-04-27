#pragma once

#include "Variant.hpp"
#include "VariantTypeImplementation.hpp"

#include <string>


namespace EasyVariant
{

// int, 0
/*
template<> 
struct VariantTypeAtIndex<1>
{
    using type = int;
};

template<> 
struct VariantIndexForType<int>
{
    static constexpr uintptr_t index = 1;
};

VariantTypeImplementation variantIntHelpers
{
    1,
    [](void*&, void*){},
    [](void*){} // no dynamic memory allocated
};


// float, 2

template<> 
struct VariantTypeAtIndex<2>
{
    using type = float;
};

template<> 
struct VariantIndexForType<float>
{
    static constexpr uintptr_t index = 2;
};

VariantTypeImplementation variantFloatHelpers
{
    2,
    [](void*&, void*){},
    [](void*){}
};


// test struct, 3

struct TestStruct
{
    int int1;
    int int2;
    void * somePtr;
    float someFloat;
};

template<> 
struct VariantTypeAtIndex<3>
{
    using type = TestStruct;
};

template<> 
struct VariantIndexForType<TestStruct>
{
    static constexpr uintptr_t index = 3;
};

VariantTypeImplementation variantTestStructHelpers
{
    3,
    [](void*&, void*){},
    [](void* value){ delete static_cast<TestStruct*>(value); }
};


// std::string, 4

template<> 
struct VariantTypeAtIndex<4>
{
    using type = std::string;
};

template<> 
struct VariantIndexForType<std::string>
{
    static constexpr uintptr_t index = 4;
};

VariantTypeImplementation variantStdStringHelpers
{
    4,
    [](void*&, void*){},
    [](void* value){ delete static_cast<std::string*>(value); }
};


*/
}

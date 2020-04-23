#pragma once

#include "Variant.hpp"
#include <string>


namespace ZigZag
{


template<> 
struct VariantTypeAtIndex<1>
{
    using type = int;
};

template<> 
struct VariantIndexForType<int>
{
    static constexpr uintPtr index = 1;
};

template<> 
struct VariantTypeAtIndex<2>
{
    using type = float;
};

template<> 
struct VariantIndexForType<float>
{
    static constexpr uintPtr index = 2;
};

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
    static constexpr uintPtr index = 3;
};

template<> 
struct VariantTypeAtIndex<4>
{
    using type = std::string;
};

template<> 
struct VariantIndexForType<std::string>
{
    static constexpr uintPtr index = 4;
};


}


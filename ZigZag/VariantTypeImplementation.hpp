#pragma once

#include <cstdint>
#include <functional>
#include <unordered_map>


namespace ZigZag
{
    

    template<int index>
    struct VariantTypeAtIndex
    {
        using type = void;
    };


    template<typename T>
    struct VariantIndexForType
    {
        static constexpr uintptr_t index = 0;
    };


    struct VariantTypeImplementation
    {
    public:
        
        using CopyFn = std::function<void(void*&, void*)>;
        using DestructFn = std::function<void(void*)>;
        using EqualFn = std::function<bool(void*, void*)>;

        VariantTypeImplementation(uintptr_t typeIndex, CopyFn&& copy, DestructFn&& destruct, EqualFn&& equal); 

        const CopyFn copy;
        const DestructFn destruct;
        const EqualFn equal;

    private:

        friend class Variant;

        static std::unordered_map<uintptr_t, VariantTypeImplementation*>* getRegisteredTypes();

    };


} // namespace ZigZag

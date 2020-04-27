#pragma once

#include <cstdint>
#include <functional>
#include <unordered_map>


namespace EasyVariant
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

        VariantTypeImplementation(uintptr_t typeIndex, CopyFn&& copy, DestructFn&& destruct); 

        const CopyFn copy;
        const DestructFn destruct;


    private:

        friend class Variant;

        static std::unordered_map<uintptr_t, VariantTypeImplementation*>* getRegisteredTypes();

    };


} // namespace EasyVariant

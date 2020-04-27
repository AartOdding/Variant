#pragma once

#include "VariantTypeImplementation.hpp"


#define VARIANT_REGISTER_TYPE(TYPE, INDEX)                                                \
                                                                                          \
                                                                                          \
namespace EasyVariant                                                                     \
{                                                                                         \
                                                                                          \
    template<>                                                                            \
    struct VariantTypeAtIndex<INDEX>                                                      \
    {                                                                                     \
        using type = TYPE;                                                                \
    };                                                                                    \
                                                                                          \
    template<>                                                                            \
    struct VariantIndexForType<TYPE>                                                      \
    {                                                                                     \
        static constexpr uintptr_t index = INDEX;                                         \
    };                                                                                    \
                                                                                          \
    const inline VariantTypeImplementation variantImplementation_##INDEX                  \
    {                                                                                     \
        INDEX,                                                                            \
        [](void*& ptr, void* other)                                                       \
        {                                                                                 \
            if constexpr (sizeof(TYPE) > sizeof(void*))                                   \
            {                                                                             \
                ptr = new TYPE(*static_cast<TYPE*>(other));                               \
            }                                                                             \
        },                                                                                \
        [](void* ptr)                                                                     \
        {                                                                                 \
            if constexpr (sizeof(TYPE) > sizeof(void*))                                   \
            {                                                                             \
                delete static_cast<TYPE*>(ptr);                                           \
            }                                                                             \
        }                                                                                 \
    };                                                                                    \
                                                                                          \
}

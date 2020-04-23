#pragma once

#include <cstdint>
#include <functional>
#include <type_traits>
#include <stdexcept>


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
    using Destructor = std::function<void(void*&)>;

    VariantHelperMethods(uintPtr typeIndex, Constructor&& constructor, Destructor&& destructor);

    const std::function<void(void*&, void*)> construct;
    const std::function<void(void*&)> destruct;
};


class Variant
{
public:

    bool isNull() const;

    // Will set the variant to null
    void clear();

    template<typename T>
    const T& get() const
    {
        //using T_ = std::remove_cv<std::remove_reference<T>::type>::type;
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
        //static_assert(std::is_same<T, T_>::value, "Type is not allowed to be const, volatile, or a reference type.");
        static_assert(VariantIndexForType<T>::index >= 0, "Type must be able to be stored in Variant.");

        if constexpr(sizeof(T) > sizeof(void*))
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                return *static_cast<T*>(m_data);
            }
            else
            {
                throw std::runtime_error("Trying to access variant with incompatible type.");
            }
        }
        else
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                return *reinterpret_cast<T*>(&m_data);
            }
            else
            {
                throw std::runtime_error("Trying to access variant with incompatible type.");
            }
        }
    }

    template<typename T>
    T& get()
    {
        //using T_ = std::remove_cv<std::remove_reference<T>::type>::type;
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
        //static_assert(std::is_same<T, T_>::value, "Type is not allowed to be const, volatile, or a reference type.");
        static_assert(VariantIndexForType<T>::index >= 0, "Type must be able to be stored in Variant.");

        if constexpr(sizeof(T) > sizeof(void*))
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                return *static_cast<T*>(m_data);
            }
            else
            {
                throw std::runtime_error("Trying to access variant with the wrong type.");
            }
        }
        else
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                return *reinterpret_cast<T*>(&m_data);
            }
            else
            {
                throw std::runtime_error("Trying to access variant with the wrong type.");
            }
        }
    }

    template<typename T>
    void set(const T& value)
    {
        //using T_ = std::remove_cv<std::remove_reference<T>::type>::type;
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
        //static_assert(std::is_same<T, T_>::value, "Type is not allowed to be const, volatile, or a reference type.");
        static_assert(VariantIndexForType<T>::index >= 0, "Type must be able to be stored in Variant.");
        
        if constexpr(sizeof(T) > sizeof(void*))
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                *static_cast<T*>(m_data) = value;
            }
            else
            {
                if (m_typeIndex >= 0)
                {
                    // delete old
                    // 
                }
                // create new
                
                m_typeIndex = VariantIndexForType<T>::index;
            }
            
        }
        else
        {
            if (m_typeIndex >= 0)
            {
                // delete old
            }
            *reinterpret_cast<T*>(&m_data) = value;
            m_typeIndex = VariantIndexForType<T>::index;
        }
    }

private:

    friend class VariantHelperMethods;

    void* m_data = nullptr;
    uintPtr m_typeIndex = 0;

    static std::unordered_map<uintPtr, VariantHelperMethods*> registeredVariantTypes;

};

}

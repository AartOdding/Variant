#pragma once

#include <cstdint>
#include <type_traits>

#include <ZigZag/VariantTypeImplementation.hpp>



namespace ZigZag
{


    class Variant
    {
    public:

        Variant() = default;
        Variant(const Variant&);
        Variant(Variant&&);

        template<typename T>
        Variant(T&& value)
            : m_data(nullptr),
              m_typeIndex(0)
        {
            set<T>(std::forward<T>(value));
        }

        ~Variant();


        void clear();

        bool isNull() const;


        template<typename T>
        bool contains() const
        {
            static_assert(VariantIndexForType<T>::index != 0, "Type must be able to be stored in Variant.");
            return m_typeIndex == VariantIndexForType<T>::index;
        }


        template<typename T> 
        T& get()
        {
            using DataType = typename std::remove_reference<T>::type;
            static_assert(VariantIndexForType<DataType>::index != 0, "Type must be able to be stored in Variant.");

            if constexpr(sizeof(DataType) > sizeof(void*))
            {
                if (m_typeIndex == VariantIndexForType<DataType>::index)
                {
                    return *static_cast<DataType*>(m_data);
                }
                else
                {
                    throw std::runtime_error("Trying to access variant of incompatible type.");
                }
            }
            else
            {
                if (m_typeIndex == VariantIndexForType<DataType>::index)
                {
                    return *reinterpret_cast<DataType*>(&m_data);
                }
                else
                {
                    throw std::runtime_error("Trying to access variant of incompatible type.");
                }
            }
        }

        template<typename T>
        const T& get() const
        {
            using DataType = typename std::remove_reference<T>::type;
            static_assert(VariantIndexForType<DataType>::index != 0, "Type must be able to be stored in Variant.");

            if constexpr(sizeof(DataType) > sizeof(void*))
            {
                if (m_typeIndex == VariantIndexForType<DataType>::index)
                {
                    return *static_cast<DataType*>(m_data);
                }
                else
                {
                    throw std::runtime_error("Trying to access variant of incompatible type.");
                }
            }
            else
            {
                if (m_typeIndex == VariantIndexForType<DataType>::index)
                {
                    return *reinterpret_cast<DataType*>(&m_data);
                }
                else
                {
                    throw std::runtime_error("Trying to access variant of incompatible type.");
                }
            }
        }


        template<typename T>
        void set(T&& value)
        {
            using DataType = typename std::remove_reference<T>::type;
            static_assert(VariantIndexForType<DataType>::index != 0, "Type must be able to be stored in Variant.");
            
            if constexpr(sizeof(DataType) > sizeof(void*))
            {
                if (m_typeIndex == VariantIndexForType<DataType>::index)
                {
                    *static_cast<DataType*>(m_data) = std::forward<T>(value);
                }
                else
                {
                    if (m_typeIndex > 0)
                    {
                        destruct();
                    }
                    m_data = new DataType(std::forward<T>(value));
                    m_typeIndex = VariantIndexForType<DataType>::index;
                }
            }
            else
            {
                if (m_typeIndex == VariantIndexForType<DataType>::index)
                {
                    m_data = reinterpret_cast<void*>(value);
                }
                else
                {
                    if (m_typeIndex > 0)
                    {
                        destruct();
                    }
                    m_data = reinterpret_cast<void*>(value);
                    m_typeIndex = VariantIndexForType<DataType>::index;
                }
            }
        }

        template<typename T>
        Variant& operator=(T&& value)
        {
            set<T>(std::forward<T>(value));
            return *this;
        }

        Variant& operator=(const Variant& other);
        Variant& operator=(Variant&& other);

        bool operator==(const Variant& other) const;

    private:

        void destruct();

        void* m_data = nullptr;
        uintptr_t m_typeIndex = 0;

    };


} // namespace ZigZag

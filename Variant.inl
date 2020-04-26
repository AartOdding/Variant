#include <utility>


namespace ZigZag
{

    template<typename T>
    T& Variant::get()
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
    const T& Variant::get() const
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
    void Variant::set(T&& value)
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
                if (m_typeIndex >= 0)
                {
                    destruct();
                }
                m_data = new DataType(std::forward<T>(value));
                m_typeIndex = VariantIndexForType<DataType>::index;
            }
        }
        else
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                m_data = reinterpret_cast<void*>(value);
            }
            else
            {
                if (m_typeIndex >= 0)
                {
                    destruct();
                }
                m_data = reinterpret_cast<void*>(value);
                m_typeIndex = VariantIndexForType<T>::index;
            }
        }
    }

}

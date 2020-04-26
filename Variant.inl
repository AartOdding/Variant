


namespace ZigZag
{

    template<typename T>
    T& Variant::get()
    {
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
        static_assert(VariantIndexForType<T>::index >= 0, "Type must be able to be stored in Variant.");

        if constexpr(sizeof(T) > sizeof(void*))
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                return *static_cast<T*>(m_data);
            }
            else
            {
                throw std::runtime_error("Trying to access variant of incompatible type.");
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
                throw std::runtime_error("Trying to access variant of incompatible type.");
            }
        }
    }


    template<typename T>
    const T& Variant::get() const
    {
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
        static_assert(VariantIndexForType<T>::index >= 0, "Type must be able to be stored in Variant.");

        if constexpr(sizeof(T) > sizeof(void*))
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                return *static_cast<T*>(m_data);
            }
            else
            {
                throw std::runtime_error("Trying to access variant of incompatible type.");
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
                throw std::runtime_error("Trying to access variant of incompatible type.");
            }
        }
    }

    
    template<typename T>
    void Variant::set(const T& value)
    {
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
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
                    destruct();
                }
                m_data = new T(value);
                m_typeIndex = VariantIndexForType<T>::index;
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

    
    template<typename T>
    void Variant::set(T&& value)
    {
        static_assert(!std::is_reference<T>::value, "Type is not allowed to be a reference.");
        static_assert(VariantIndexForType<T>::index >= 0, "Type must be able to be stored in Variant.");
        
        if constexpr(sizeof(T) > sizeof(void*))
        {
            if (m_typeIndex == VariantIndexForType<T>::index)
            {
                *static_cast<T*>(m_data) = std::move(value);
            }
            else
            {
                if (m_typeIndex >= 0)
                {
                    destruct();
                }
                m_data = new T(std::move(value));
                m_typeIndex = VariantIndexForType<T>::index;
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

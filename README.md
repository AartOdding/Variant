# ZigZag Variant
A Variant type originally developed for usage in ZigZag. Instead of Variant being a class template such as in the C++ standard library, this Variant type is based on the Qt approach where a Variant is only a pointer to a value and an integer representing the index of the currently stored type. By defualt it also uses small type optimization so that values no larger than a pointer do not need to be dynamically allocated. The size of a Variant is always 2 * sizeof(void*), no matter what architecture you are compiling for. Becuase of this moving variant around and swapping them is very efficient, but copying a Variant creates a deep copy of the contained data.

# Usage
The Variant type as is, does not support storing any types by default. The easiest way to add support for types is using the type registration macro: `ZIGZAG_VARIANT_REGISTER_TYPE(float, 5)` where float is the type currently being registered and 5 is the index that this type will be assigned to. Trying to assign multiple types to the same index will generate compile errors. This macro will be expanded to two type traits and an instance of a helper class that defines a copy constructor and destructor for the type. If you do not want to use this macro you can also define these manually. See ZigZag/VariantRegisterType.hpp to see how to do this.

# Building
ZigZag Variant uses CMake to build itself into a library, that can then easily be added to other cmake projects. If you do not want to use CMake it is also possible to just copy the ZigZag folder into your project.

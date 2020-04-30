# ZigZag Variant
A Variant type originally developed for usage in ZigZag. Instead of Variant being a class template such as in the C++ standard library, this Variant type is based on the Qt approach where a Variant is only a pointer to a value and an integer representing the index of the currently stored type. There is also a small type optimization where values that are no larger than a pointer do not need to be dynamically allocated. The size of a Variant is always 2 * sizof(void*), on 32 and 64 bit architectures.

# Usage
The Variant type as is, does not support storing any types by default. The easiest way to add support for types is using the type registration macro:


cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(ZigZagVariant)

add_library(
    ZigZagVariant STATIC
    ZigZag/Variant.cpp
    ZigZag/VariantTypeImplementation.cpp)

target_include_directories(ZigZagVariant PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})
    
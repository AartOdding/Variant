cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(EasyVariant)

add_library(
    EasyVariant STATIC
    Variant.cpp
    VariantTypeImplementation.cpp)

target_include_directories(EasyVariant PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})
    
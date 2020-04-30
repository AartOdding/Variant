cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(VariantTest)


add_executable(
    VariantTest
    main.cpp
    ../ZigZag/Variant.cpp
    ../ZigZag/VariantTypeImplementation)

target_include_directories(VariantTest PRIVATE ../)

cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(EasyVariantTest)


add_executable(
    EasyVariantTest
    main.cpp
    ../Variant.cpp
    ../VariantTypeImplementation)

target_include_directories(EasyVariantTest PRIVATE ../)

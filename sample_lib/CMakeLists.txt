cmake_minimum_required(VERSION 3.12)
project(ComplexLibrary LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_library(complex STATIC Complex.cpp Complex.h)

# Include current directory for headers
target_include_directories(complex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

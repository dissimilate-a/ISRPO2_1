cmake_minimum_required(VERSION 3.16)
project(complex_app LANGUAGES CXX)

add_executable(complex_app main.cpp)

target_link_libraries(complex_app PRIVATE complex)

target_include_directories(complex_app PRIVATE ${CMAKE_SOURCE_DIR}/sample_lib)

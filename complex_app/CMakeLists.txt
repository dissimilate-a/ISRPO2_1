# Console application to demonstrate complex library
add_executable(complex_app main.cpp)

# Link with the complex library
target_link_libraries(complex_app complex)

# Include directories
target_include_directories(complex_app PRIVATE ${CMAKE_SOURCE_DIR}/complex_lib)
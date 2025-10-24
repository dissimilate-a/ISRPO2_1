# Test executable for complex library
add_executable(test_complex test_complex.cpp)

# Link with the complex library
target_link_libraries(test_complex complex)

# Include directories
target_include_directories(test_complex PRIVATE ${CMAKE_SOURCE_DIR}/complex_lib)

# Add test
add_test(NAME ComplexLibraryTest COMMAND test_complex)
cmake_minimum_required(VERSION 3.12)
project(DemoProject LANGUAGES CXX VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler-specific options
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find OpenCV
find_package(OpenCV REQUIRED)

# Add the complex library from parent directory
add_subdirectory(../sample_lib complex_lib)

# Create executable
add_executable(demo main.cpp)

# Link with OpenCV and complex library
target_link_libraries(demo 
    ${OpenCV_LIBS}
    complex
)

# Include directories
target_include_directories(demo PRIVATE 
    ${OpenCV_INCLUDE_DIRS}
    ../sample_lib
)

# Set output directory
set_target_properties(demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Print configuration info
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")

# Install target
install(TARGETS demo
    RUNTIME DESTINATION bin
)
cmake_minimum_required(VERSION 3.12)
project(ComplexLibraryProject LANGUAGES CXX)

# Enable testing
enable_testing()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add subdirectories
add_subdirectory(complex_lib)
add_subdirectory(complex_app)
add_subdirectory(test)

# Check if OpenCV is available for face detection
find_package(OpenCV QUIET)
if(OpenCV_FOUND)
    add_subdirectory(face_detect)
    set(FACE_DETECT_AVAILABLE TRUE)
else()
    set(FACE_DETECT_AVAILABLE FALSE)
endif()

# Print configuration summary
message(STATUS "Configuration Summary:")
message(STATUS "  Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "  Face detection app: ${FACE_DETECT_AVAILABLE}")
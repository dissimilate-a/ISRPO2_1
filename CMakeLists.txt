cmake_minimum_required(VERSION 3.16)
project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_FACE_DETECT "Build OpenCV face detection demo" ON)

# Add complex number static library
add_subdirectory(sample_lib)

# Demo: Complex app
add_subdirectory(demos/complex_app)

# Demo: Face detection with OpenCV
if(BUILD_FACE_DETECT)
  add_subdirectory(demos/face_detect)
endif()

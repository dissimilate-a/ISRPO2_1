cmake_minimum_required(VERSION 3.16)
project(ComplexSuite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Options
option(BUILD_FACE_DETECT "Build OpenCV face detection app" ON)

# Library
add_subdirectory(sample_lib)

# Console app using complex lib
add_subdirectory(apps/complex_app)

# OpenCV app (optional)
if(BUILD_FACE_DETECT)
  add_subdirectory(apps/face_detect)
endif()

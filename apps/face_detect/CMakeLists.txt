cmake_minimum_required(VERSION 3.16)

find_package(OpenCV QUIET COMPONENTS core imgproc objdetect highgui)

if(NOT OpenCV_FOUND)
  message(WARNING "OpenCV not found; skipping face_detect build")
  return()
endif()

# Ensure Haar cascade is available next to the binary
# Download at configure time to the current binary directory if missing
set(_cascade_xml "${CMAKE_CURRENT_BINARY_DIR}/haarcascade_frontalface_alt2.xml")
if(NOT EXISTS "${_cascade_xml}")
  message(STATUS "Downloading Haar cascade to ${_cascade_xml}")
  file(DOWNLOAD
    "https://raw.githubusercontent.com/opencv/opencv/4.x/data/haarcascades/haarcascade_frontalface_alt2.xml"
    "${_cascade_xml}"
    SHOW_PROGRESS
    TLS_VERIFY ON
  )
endif()

add_executable(face_detect main.cpp)

target_link_libraries(face_detect PRIVATE ${OpenCV_LIBS})

target_include_directories(face_detect PRIVATE ${OpenCV_INCLUDE_DIRS})

target_compile_features(face_detect PRIVATE cxx_std_17)

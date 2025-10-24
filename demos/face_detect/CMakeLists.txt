cmake_minimum_required(VERSION 3.16)
project(face_detect LANGUAGES CXX)

find_package(OpenCV QUIET)

if(NOT OpenCV_FOUND)
  message(WARNING "OpenCV not found. The face_detect target will not be built.\n"
                  "Install OpenCV (e.g., libopencv-dev) or set OpenCV_DIR to your OpenCV build.")
  return()
endif()

add_executable(face_detect main.cpp)

# Include and link OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(face_detect PRIVATE ${OpenCV_LIBS})

# On some systems, need to add rpath for local OpenCV builds
if(APPLE)
  set_target_properties(face_detect PROPERTIES INSTALL_RPATH "@loader_path")
elseif(UNIX)
  set_target_properties(face_detect PROPERTIES INSTALL_RPATH "$ORIGIN")
endif()

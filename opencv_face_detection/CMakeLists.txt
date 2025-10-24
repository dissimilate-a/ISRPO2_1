cmake_minimum_required(VERSION 3.12)
project(OpenCVFaceDetection LANGUAGES CXX VERSION 1.0.0)

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

# Print OpenCV information
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")

# Create executable
add_executable(face_detection face_detection.cpp)

# Link with OpenCV
target_link_libraries(face_detection ${OpenCV_LIBS})

# Include OpenCV headers
target_include_directories(face_detection PRIVATE ${OpenCV_INCLUDE_DIRS})

# Set output directory
set_target_properties(face_detection PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy cascade file to build directory
find_file(HAARCASCADE_FILE 
    NAMES haarcascade_frontalface_alt2.xml
    PATHS 
        /usr/share/opencv4/haarcascades
        /usr/local/share/opencv4/haarcascades
        /opt/opencv/share/opencv4/haarcascades
        ${OpenCV_INSTALL_PATH}/etc/haarcascades
    NO_DEFAULT_PATH
)

if(HAARCASCADE_FILE)
    message(STATUS "Found cascade file: ${HAARCASCADE_FILE}")
    configure_file(${HAARCASCADE_FILE} 
        ${CMAKE_BINARY_DIR}/bin/haarcascade_frontalface_alt2.xml 
        COPYONLY
    )
else()
    message(WARNING "Cascade file not found. Please ensure it's available at runtime.")
endif()

# Create executable for test image generation
add_executable(create_test_image create_test_image.cpp)
target_link_libraries(create_test_image ${OpenCV_LIBS})
target_include_directories(create_test_image PRIVATE ${OpenCV_INCLUDE_DIRS})

# Create executable for realistic test image generation
add_executable(create_realistic_test create_realistic_test.cpp)
target_link_libraries(create_realistic_test ${OpenCV_LIBS})
target_include_directories(create_realistic_test PRIVATE ${OpenCV_INCLUDE_DIRS})

# Custom target to run test image creation
add_custom_target(run_test_image_creation
    COMMAND create_test_image
    DEPENDS create_test_image
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMENT "Creating test image for face detection demo"
)

# Install target
install(TARGETS face_detection
    RUNTIME DESTINATION bin
)

# Install cascade file if found
if(HAARCASCADE_FILE)
    install(FILES ${HAARCASCADE_FILE}
        DESTINATION share/opencv4/haarcascades
        RENAME haarcascade_frontalface_alt2.xml
    )
endif()
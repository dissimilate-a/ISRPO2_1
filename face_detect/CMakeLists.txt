# OpenCV face detection application
find_package(OpenCV QUIET)

if(OpenCV_FOUND)
    add_executable(face_detect face_detection.cpp)
    
    # Link with OpenCV
    target_link_libraries(face_detect ${OpenCV_LIBS})
    
    # Include OpenCV headers
    target_include_directories(face_detect PRIVATE ${OpenCV_INCLUDE_DIRS})
    
    # Set C++ standard
    set_target_properties(face_detect PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )
    
    message(STATUS "OpenCV found - face detection application will be built")
else()
    message(STATUS "OpenCV not found - face detection application will be skipped")
    message(STATUS "To build face detection app, install OpenCV and reconfigure")
endif()
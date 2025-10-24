cmake_minimum_required(VERSION 3.12)
project(ComplexLibrary LANGUAGES CXX VERSION 1.0.0)

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

# Add the library
add_library(complex STATIC 
    Complex.cpp 
    Complex.h
)

# Include current directory for headers
target_include_directories(complex PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Set properties for the library
set_target_properties(complex PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER Complex.h
)

# Create an alias for the target
add_library(ComplexLibrary::complex ALIAS complex)

# Install targets
install(TARGETS complex
    EXPORT ComplexLibraryTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)

# Install headers
install(FILES Complex.h DESTINATION include)

# Export targets
install(EXPORT ComplexLibraryTargets
    FILE ComplexLibraryTargets.cmake
    NAMESPACE ComplexLibrary::
    DESTINATION lib/cmake/ComplexLibrary
)

# Create config file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ComplexLibraryConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ComplexLibraryConfigVersion.cmake
    DESTINATION lib/cmake/ComplexLibrary
)

# Create config.cmake file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/ComplexLibraryConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ComplexLibraryConfig.cmake
    INSTALL_DESTINATION lib/cmake/ComplexLibrary
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ComplexLibraryConfig.cmake
    DESTINATION lib/cmake/ComplexLibrary
)

# Demo application
add_executable(complex_demo demo.cpp)
target_link_libraries(complex_demo complex)

# Set output directory for demo
set_target_properties(complex_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

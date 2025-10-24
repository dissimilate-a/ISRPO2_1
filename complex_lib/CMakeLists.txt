# Complex number library
add_library(complex STATIC Complex.cpp Complex.h)

# Include current directory for headers
target_include_directories(complex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set properties
set_target_properties(complex PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
)

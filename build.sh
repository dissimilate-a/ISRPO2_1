#!/bin/bash

# Build script for Complex Number Library Project

echo "=== Complex Number Library Project Build Script ==="
echo

# Check if build directory exists, create if not
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build

echo "Configuring project with CMake..."
cmake ..

if [ $? -eq 0 ]; then
    echo "Configuration successful!"
    echo
    echo "Building project..."
    cmake --build .
    
    if [ $? -eq 0 ]; then
        echo
        echo "Build successful!"
        echo
        echo "Available executables:"
        echo "  - complex_app/complex_app (console demonstration)"
        if [ -f "face_detect/face_detect" ]; then
            echo "  - face_detect/face_detect (face detection - requires OpenCV)"
        else
            echo "  - face_detect/face_detect (not built - OpenCV not found)"
        fi
        echo
        echo "To run the console app: ./complex_app/complex_app"
    else
        echo "Build failed!"
        exit 1
    fi
else
    echo "Configuration failed!"
    exit 1
fi
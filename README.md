# Complex Number Library Project

This project demonstrates CMake usage for building a C++ library and applications. It includes:

1. **Complex Number Library** (`complex_lib/`) - A static library implementing complex number arithmetic
2. **Console Application** (`complex_app/`) - Demonstrates the complex library functionality
3. **Face Detection Application** (`face_detect/`) - OpenCV-based face detection using the complex library

## Project Structure

```
.
├── CMakeLists.txt              # Top-level CMake configuration
├── complex_lib/                # Complex number library
│   ├── CMakeLists.txt
│   ├── Complex.h              # Complex class header
│   └── Complex.cpp            # Complex class implementation
├── complex_app/               # Console demonstration app
│   ├── CMakeLists.txt
│   └── main.cpp
├── face_detect/               # OpenCV face detection app
│   ├── CMakeLists.txt
│   └── face_detection.cpp
└── README.md
```

## Complex Number Operations

The library implements the four basic operations for complex numbers:

1. **Addition**: (a + bi) + (c + di) = (a + c) + (b + d)i
2. **Subtraction**: (a + bi) - (c + di) = (a - c) + (b - d)i
3. **Multiplication**: (a + bi) × (c + di) = (ac - bd) + (ad + bc)i
4. **Division**: (a + bi) ÷ (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)

## Building the Project

### Prerequisites

- CMake 3.12 or higher
- C++17 compatible compiler
- OpenCV (for face detection application)

### Build Instructions

1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Configure with CMake:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

### Running the Applications

1. **Console Application** (demonstrates complex library):
   ```bash
   ./complex_app/complex_app
   ```

2. **Face Detection Application** (requires webcam and OpenCV):
   ```bash
   # Download the Haar cascade file first:
   wget https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_alt2.xml
   
   # Run the application:
   ./face_detect/face_detect
   ```

## Usage

### Complex Library

```cpp
#include "Complex.h"

Complex a(3.0, 4.0);  // 3 + 4i
Complex b(1.0, 2.0);  // 1 + 2i

Complex sum = a + b;      // Addition
Complex diff = a - b;     // Subtraction
Complex product = a * b;  // Multiplication
Complex quotient = a / b; // Division
```

### Face Detection

The face detection application uses OpenCV's Haar cascade classifier to detect faces in real-time video from the default camera. Controls:
- Press 'q' or ESC to quit
- Press 's' to save current frame

## CMake Features Demonstrated

- Modular project structure with subdirectories
- Static library creation and linking
- External dependency management (OpenCV)
- C++17 standard enforcement
- Cross-platform build configuration
# Installing OpenCV for Face Detection Application

The face detection application requires OpenCV to be installed. Here are installation instructions for different platforms:

## Ubuntu/Debian

```bash
sudo apt update
sudo apt install libopencv-dev
```

## CentOS/RHEL/Fedora

```bash
# For CentOS/RHEL 8+
sudo dnf install opencv-devel

# For older versions
sudo yum install opencv-devel
```

## macOS (with Homebrew)

```bash
brew install opencv
```

## Windows (with vcpkg)

```bash
vcpkg install opencv
```

## Building from Source

If you prefer to build OpenCV from source:

1. Download OpenCV from https://opencv.org/releases/
2. Extract and create build directory:
   ```bash
   cd opencv-4.x.x
   mkdir build && cd build
   ```
3. Configure with CMake:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release ..
   ```
4. Build and install:
   ```bash
   make -j4
   sudo make install
   ```

## After Installing OpenCV

1. Clean and reconfigure the project:
   ```bash
   rm -rf build
   mkdir build && cd build
   cmake ..
   ```

2. Build the project:
   ```bash
   cmake --build .
   ```

3. Download the Haar cascade file:
   ```bash
   wget https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_alt2.xml
   ```

4. Run the face detection application:
   ```bash
   ./face_detect/face_detect
   ```

## Verification

To verify OpenCV installation:

```bash
pkg-config --modversion opencv4
# or
pkg-config --modversion opencv
```

The face detection application will automatically detect if OpenCV is available and build accordingly.
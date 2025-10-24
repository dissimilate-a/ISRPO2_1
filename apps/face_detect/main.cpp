#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
 #include <filesystem>

static std::string getExecutableDir() {
    char buffer[PATH_MAX];
    ssize_t len = ::readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len == -1) {
        return std::string(".");
    }
    buffer[len] = '\0';
    std::string exePath(buffer);
    auto pos = exePath.find_last_of('/');
    if (pos == std::string::npos) {
        return std::string(".");
    }
    return exePath.substr(0, pos);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: face_detect <image_path> [cascade_path] [--out output_path] [--no-gui]\n";
        return 1;
    }

    std::string imagePath = argv[1];
    // Default cascade: look next to the executable
    std::string cascadePath = (argc >= 3 && std::string(argv[2]).rfind("--", 0) != 0)
        ? std::string(argv[2])
        : (getExecutableDir() + "/haarcascade_frontalface_alt2.xml");

    // Optional arguments
    std::string outputPath;
    bool noGui = false;
    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--no-gui") {
            noGui = true;
        } else if (arg == "--out" && i + 1 < argc) {
            outputPath = argv[++i];
        }
    }

    cv::Mat image = cv::imread(imagePath);
    if (image.empty()) {
        std::cerr << "Failed to read image: " << imagePath << std::endl;
        return 1;
    }

    cv::CascadeClassifier faceCascade;
    if (!faceCascade.load(cascadePath)) {
        std::cerr << "Failed to load cascade: " << cascadePath << std::endl;
        return 1;
    }

    std::vector<cv::Rect> faces;
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    faceCascade.detectMultiScale(gray, faces);

    for (const auto& face : faces) {
        cv::rectangle(image, face, cv::Scalar(0, 255, 0), 2);
    }

    std::cout << "Detected faces: " << faces.size() << std::endl;

    // Determine if GUI is available (common check on Linux)
    const bool headless = (std::getenv("DISPLAY") == nullptr) && (std::getenv("WAYLAND_DISPLAY") == nullptr);

    // Save output if requested or if running headless
    if (outputPath.empty() && headless) {
        // Derive default output path next to input
        try {
            std::filesystem::path in(imagePath);
            std::filesystem::path out = in.parent_path() / (in.stem().string() + "_faces" + in.extension().string());
            outputPath = out.string();
        } catch (...) {
            outputPath = "faces_out.jpg";
        }
    }

    if (!outputPath.empty()) {
        if (!cv::imwrite(outputPath, image)) {
            std::cerr << "Failed to write output image: " << outputPath << std::endl;
        } else {
            std::cout << "Saved: " << outputPath << std::endl;
        }
    }

    if (!headless && !noGui) {
        // Show result only when a display is available
        cv::imshow("Faces", image);
        cv::waitKey(0);
    }

    return 0;
}

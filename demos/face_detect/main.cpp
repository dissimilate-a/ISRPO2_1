#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "Usage: face_detect <path_to_haarcascade_frontalface_alt2.xml> <image_path>\n";
        return 1;
    }

    std::string cascadePath = argv[1];
    std::string imagePath = argv[2];

    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load(cascadePath)) {
        std::cerr << "Error loading cascade xml: " << cascadePath << "\n";
        return 2;
    }

    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Could not read image: " << imagePath << "\n";
        return 3;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, cv::Size(30, 30));

    for (const auto& r : faces) {
        cv::rectangle(img, r, cv::Scalar(0, 255, 0), 2);
    }

    std::cout << "Detected faces: " << faces.size() << "\n";

    // Save result next to input file
    std::string outPath = imagePath + ".faces.jpg";
    if (!cv::imwrite(outPath, img)) {
        std::cerr << "Failed to write output: " << outPath << "\n";
        return 4;
    }
    std::cout << "Wrote: " << outPath << "\n";

    return 0;
}

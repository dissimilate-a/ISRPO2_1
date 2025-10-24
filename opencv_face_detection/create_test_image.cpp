#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    // Create a simple test image with a face-like pattern
    Mat img = Mat::ones(400, 600, CV_8UC3) * 255;
    
    // Draw a simple face
    circle(img, Point(300, 200), 80, Scalar(200, 200, 200), -1);  // Face
    circle(img, Point(280, 180), 10, Scalar(0, 0, 0), -1);        // Left eye
    circle(img, Point(320, 180), 10, Scalar(0, 0, 0), -1);        // Right eye
    ellipse(img, Point(300, 220), Size(20, 10), 0, 0, 180, Scalar(0, 0, 0), 2);  // Mouth
    
    // Save the image
    imwrite("test_image.jpg", img);
    std::cout << "Test image created: test_image.jpg" << std::endl;
    
    return 0;
}
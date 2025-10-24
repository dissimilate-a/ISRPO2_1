#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;

int main() {
    // Create a larger test image with multiple faces
    Mat img = Mat::ones(600, 800, CV_8UC3) * 240; // Light gray background
    
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(50, 150);
    
    // Create multiple faces
    std::vector<Point> face_centers = {
        Point(200, 200),  // Face 1
        Point(500, 250),  // Face 2
        Point(350, 450),  // Face 3
        Point(150, 400)   // Face 4
    };
    
    for (size_t i = 0; i < face_centers.size(); i++) {
        Point center = face_centers[i];
        int face_size = dis(gen);
        
        // Draw face (ellipse)
        ellipse(img, center, Size(face_size/2, face_size/2), 0, 0, 360, Scalar(220, 200, 180), -1);
        
        // Draw eyes
        circle(img, Point(center.x - face_size/4, center.y - face_size/6), face_size/12, Scalar(0, 0, 0), -1);
        circle(img, Point(center.x + face_size/4, center.y - face_size/6), face_size/12, Scalar(0, 0, 0), -1);
        
        // Draw nose
        circle(img, Point(center.x, center.y), face_size/20, Scalar(180, 160, 140), -1);
        
        // Draw mouth
        ellipse(img, Point(center.x, center.y + face_size/4), Size(face_size/6, face_size/12), 0, 0, 180, Scalar(0, 0, 0), 2);
        
        // Add some hair
        ellipse(img, Point(center.x, center.y - face_size/3), Size(face_size/2 + 10, face_size/3), 0, 0, 180, Scalar(100, 80, 60), -1);
    }
    
    // Add some background elements
    rectangle(img, Point(50, 50), Point(750, 550), Scalar(200, 200, 200), 2);
    
    // Save the image
    imwrite("realistic_test_image.jpg", img);
    std::cout << "Realistic test image created: realistic_test_image.jpg" << std::endl;
    std::cout << "Image size: " << img.cols << "x" << img.rows << std::endl;
    
    return 0;
}
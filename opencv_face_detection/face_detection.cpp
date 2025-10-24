#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

class FaceDetector {
private:
    CascadeClassifier face_cascade;
    string cascade_path;
    
public:
    FaceDetector(const string& cascade_file) : cascade_path(cascade_file) {
        if (!face_cascade.load(cascade_file)) {
            throw runtime_error("Error loading cascade classifier from: " + cascade_file);
        }
    }
    
    vector<Rect> detectFaces(const Mat& image) {
        vector<Rect> faces;
        Mat gray;
        
        // Convert to grayscale if needed
        if (image.channels() > 1) {
            cvtColor(image, gray, COLOR_BGR2GRAY);
        } else {
            gray = image.clone();
        }
        
        // Equalize histogram for better detection
        equalizeHist(gray, gray);
        
        // Detect faces
        face_cascade.detectMultiScale(
            gray,           // Input image
            faces,          // Output vector of rectangles
            1.1,            // Scale factor
            3,              // Minimum neighbors
            0,              // Flags (not used)
            Size(30, 30),   // Minimum size
            Size()          // Maximum size (no limit)
        );
        
        return faces;
    }
    
    void drawFaces(Mat& image, const vector<Rect>& faces) {
        for (const auto& face : faces) {
            // Draw rectangle around face
            rectangle(image, face, Scalar(0, 255, 0), 2);
            
            // Draw text with face number
            Point text_point(face.x, face.y - 10);
            putText(image, "Face", text_point, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
        }
    }
    
    void printDetectionInfo(const vector<Rect>& faces) {
        cout << "Detected " << faces.size() << " face(s):" << endl;
        for (size_t i = 0; i < faces.size(); i++) {
            cout << "  Face " << (i + 1) << ": x=" << faces[i].x 
                 << ", y=" << faces[i].y 
                 << ", width=" << faces[i].width 
                 << ", height=" << faces[i].height << endl;
        }
    }
};

void printUsage(const string& program_name) {
    cout << "Usage: " << program_name << " <input_image> [cascade_file]" << endl;
    cout << "  input_image: Path to input image file" << endl;
    cout << "  cascade_file: Path to cascade classifier file (optional)" << endl;
    cout << "                Default: /usr/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml" << endl;
}

int main(int argc, char* argv[]) {
    cout << "=== OpenCV Face Detection Demo ===" << endl;
    cout << "OpenCV Version: " << CV_VERSION << endl;
    cout << endl;
    
    // Check command line arguments
    if (argc < 2) {
        printUsage(argv[0]);
        return -1;
    }
    
    string input_image_path = argv[1];
    string cascade_file = (argc > 2) ? argv[2] : "/usr/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml";
    
    cout << "Input image: " << input_image_path << endl;
    cout << "Cascade file: " << cascade_file << endl;
    cout << endl;
    
    try {
        // Load input image
        Mat image = imread(input_image_path);
        if (image.empty()) {
            throw runtime_error("Could not load image: " + input_image_path);
        }
        
        cout << "Image loaded successfully:" << endl;
        cout << "  Size: " << image.cols << "x" << image.rows << endl;
        cout << "  Channels: " << image.channels() << endl;
        cout << endl;
        
        // Create face detector
        FaceDetector detector(cascade_file);
        cout << "Face detector initialized successfully" << endl;
        cout << endl;
        
        // Detect faces
        cout << "Detecting faces..." << endl;
        vector<Rect> faces = detector.detectFaces(image);
        
        // Print detection results
        detector.printDetectionInfo(faces);
        cout << endl;
        
        // Draw faces on image
        Mat result_image = image.clone();
        detector.drawFaces(result_image, faces);
        
        // Save result
        string output_path = "result_" + input_image_path;
        imwrite(output_path, result_image);
        cout << "Result saved to: " << output_path << endl;
        
        // Display images (if GUI is available)
        // Note: GUI display disabled for server environments
        cout << "Note: GUI display disabled for server environments." << endl;
        cout << "Result image saved to file instead." << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }
    
    cout << "Face detection completed successfully!" << endl;
    return 0;
}
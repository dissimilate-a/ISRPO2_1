#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main() {
    cout << "=== OpenCV Face Detection Application ===" << endl;
    cout << "Press 'q' to quit, 's' to save current frame" << endl;
    cout << endl;
    
    // Load the cascade classifier
    CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_alt2.xml")) {
        cerr << "Error: Could not load face cascade classifier!" << endl;
        cerr << "Please make sure haarcascade_frontalface_alt2.xml is in the current directory." << endl;
        return -1;
    }
    
    // Open the default camera
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera!" << endl;
        return -1;
    }
    
    Mat frame;
    int frame_count = 0;
    
    while (true) {
        // Capture frame
        cap >> frame;
        if (frame.empty()) {
            cerr << "Error: Could not capture frame!" << endl;
            break;
        }
        
        // Convert to grayscale for face detection
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, gray);
        
        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));
        
        // Draw rectangles around detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);
            
            // Add text label
            Point text_pos(faces[i].x, faces[i].y - 10);
            putText(frame, "Face " + to_string(i + 1), text_pos, 
                   FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
        }
        
        // Add frame counter and face count
        string info = "Frame: " + to_string(frame_count++) + 
                     " | Faces detected: " + to_string(faces.size());
        putText(frame, info, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 2);
        
        // Display the frame
        imshow("Face Detection", frame);
        
        // Check for key press
        char key = waitKey(1) & 0xFF;
        if (key == 'q' || key == 27) {  // 'q' or ESC
            break;
        } else if (key == 's') {  // Save current frame
            string filename = "face_detection_frame_" + to_string(frame_count) + ".jpg";
            imwrite(filename, frame);
            cout << "Frame saved as: " << filename << endl;
        }
    }
    
    // Clean up
    cap.release();
    destroyAllWindows();
    
    cout << "Face detection application closed." << endl;
    return 0;
}
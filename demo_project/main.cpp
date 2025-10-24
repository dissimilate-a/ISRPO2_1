#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

// Include our complex number library
#include "../sample_lib/Complex.h"

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
        
        if (image.channels() > 1) {
            cvtColor(image, gray, COLOR_BGR2GRAY);
        } else {
            gray = image.clone();
        }
        
        equalizeHist(gray, gray);
        face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30), Size());
        return faces;
    }
    
    void drawFaces(Mat& image, const vector<Rect>& faces) {
        for (const auto& face : faces) {
            rectangle(image, face, Scalar(0, 255, 0), 2);
            Point text_point(face.x, face.y - 10);
            putText(image, "Face", text_point, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
        }
    }
};

void demonstrateComplexNumbers() {
    cout << "\n=== ДЕМОНСТРАЦИЯ БИБЛИОТЕКИ КОМПЛЕКСНЫХ ЧИСЕЛ ===" << endl;
    cout << string(60, '=') << endl;
    
    // Создание комплексных чисел (используем полное имя класса)
    ::Complex z1(3, 4);  // 3 + 4i
    ::Complex z2(1, -2); // 1 - 2i
    
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    cout << endl;
    
    // Основные операции
    cout << "Основные операции:" << endl;
    cout << "z1 + z2 = " << (z1 + z2) << endl;
    cout << "z1 - z2 = " << (z1 - z2) << endl;
    cout << "z1 * z2 = " << (z1 * z2) << endl;
    cout << "z1 / z2 = " << (z1 / z2) << endl;
    cout << endl;
    
    // Свойства
    cout << "Свойства z1:" << endl;
    cout << "|z1| = " << z1.magnitude() << endl;
    cout << "arg(z1) = " << z1.phase() << " радиан" << endl;
    cout << "z1* = " << z1.conjugate() << endl;
    cout << endl;
    
    // Демонстрация расширенных операций
    cout << "Расширенные операции:" << endl;
    ::Complex z3(2, 1);
    cout << "z3 = " << z3 << endl;
    cout << "z3^2 = " << pow(z3, 2) << endl;
    cout << "sqrt(z3) = " << sqrt(z3) << endl;
    cout << "exp(z3) = " << exp(z3) << endl;
    cout << "log(z3) = " << log(z3) << endl;
}

void demonstrateFaceDetection() {
    cout << "\n=== ДЕМОНСТРАЦИЯ ДЕТЕКЦИИ ЛИЦ ===" << endl;
    cout << string(60, '=') << endl;
    
    try {
        // Создаем тестовое изображение
        Mat test_image = Mat::ones(400, 600, CV_8UC3) * 255;
        
        // Рисуем простое лицо
        circle(test_image, Point(300, 200), 80, Scalar(200, 200, 200), -1);
        circle(test_image, Point(280, 180), 10, Scalar(0, 0, 0), -1);
        circle(test_image, Point(320, 180), 10, Scalar(0, 0, 0), -1);
        ellipse(test_image, Point(300, 220), Size(20, 10), 0, 0, 180, Scalar(0, 0, 0), 2);
        
        cout << "Создано тестовое изображение размером " << test_image.cols << "x" << test_image.rows << endl;
        
        // Инициализация детектора лиц
        string cascade_file = "/usr/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml";
        FaceDetector detector(cascade_file);
        cout << "Детектор лиц инициализирован" << endl;
        
        // Детекция лиц
        vector<Rect> faces = detector.detectFaces(test_image);
        cout << "Найдено лиц: " << faces.size() << endl;
        
        if (!faces.empty()) {
            cout << "Координаты найденных лиц:" << endl;
            for (size_t i = 0; i < faces.size(); i++) {
                cout << "  Лицо " << (i + 1) << ": x=" << faces[i].x 
                     << ", y=" << faces[i].y 
                     << ", w=" << faces[i].width 
                     << ", h=" << faces[i].height << endl;
            }
            
            // Рисуем прямоугольники вокруг лиц
            detector.drawFaces(test_image, faces);
            imwrite("demo_face_detection_result.jpg", test_image);
            cout << "Результат сохранен в demo_face_detection_result.jpg" << endl;
        } else {
            cout << "Лица не найдены на тестовом изображении" << endl;
        }
        
    } catch (const exception& e) {
        cout << "Ошибка при детекции лиц: " << e.what() << endl;
    }
}

void printSystemInfo() {
    cout << "=== ИНФОРМАЦИЯ О СИСТЕМЕ ===" << endl;
    cout << string(60, '=') << endl;
    cout << "OpenCV версия: " << CV_VERSION << endl;
    cout << "Компилятор: " << __VERSION__ << endl;
    cout << "Дата сборки: " << __DATE__ << " " << __TIME__ << endl;
    cout << endl;
}

int main() {
    cout << "=== ДЕМОНСТРАЦИОННОЕ ПРИЛОЖЕНИЕ ===" << endl;
    cout << "Лабораторная работа 2: CMake. Сборка приложения с библиотекой" << endl;
    cout << string(80, '=') << endl;
    
    printSystemInfo();
    
    // Демонстрация библиотеки комплексных чисел
    demonstrateComplexNumbers();
    
    // Демонстрация детекции лиц
    demonstrateFaceDetection();
    
    cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << endl;
    cout << "Все компоненты работают корректно!" << endl;
    
    return 0;
}
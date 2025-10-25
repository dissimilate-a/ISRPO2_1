#include <iostream>
#include <iomanip>
#include "Complex.h"

void printComplex(const Complex& c, const std::string& name) {
    std::cout << name << " = " << std::fixed << std::setprecision(2) 
              << c.re << " + " << c.im << "i" << std::endl;
}

int main() {
    std::cout << "=== Библиотека комплексных чисел ===" << std::endl;
    std::cout << std::endl;
    
    // Создание двух комплексных чисел
    Complex a(3.0, 4.0);  // 3 + 4i
    Complex b(1.0, 2.0);  // 1 + 2i
    
    printComplex(a, "a");
    printComplex(b, "b");
    std::cout << std::endl;

    // Сложение
    Complex sum = a + b;
    printComplex(sum, "a + b");
    
    // Вычитание
    Complex diff = a - b;
    printComplex(diff, "a - b");
    
    // Умножение
    Complex product = a * b;
    printComplex(product, "a * b");
    
    // Деление
    Complex quotient = a / b;
    printComplex(quotient, "a / b");
    
    std::cout << std::endl;
    
    // Создание двух комплексных чисел
    Complex c(5.0, -3.0);  // 5 - 3i
    Complex d(2.0, 1.0);   // 2 + i
    
    printComplex(c, "c");
    printComplex(d, "d");
    std::cout << std::endl;
    
    printComplex(c + d, "c + d");
    printComplex(c - d, "c - d");
    printComplex(c * d, "c * d");
    printComplex(c / d, "c / d");
    
    std::cout << std::endl;
    std::cout << "=== Операции над действительными числами ===" << std::endl;

    // Создаём комплексные числа, которые по сути являются действительными (мнимая часть 0)
    Complex real1(7.0, 0.0);  // 7
    Complex real2(3.0, 0.0);  // 3
    
    printComplex(real1, "real1");
    printComplex(real2, "real2");
    std::cout << std::endl;
    
    printComplex(real1 + real2, "real1 + real2");
    printComplex(real1 - real2, "real1 - real2");
    printComplex(real1 * real2, "real1 * real2");
    printComplex(real1 / real2, "real1 / real2");
    Console.ReadKey();
    return 0;
}
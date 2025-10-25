#include <iostream>
#include <iomanip>
#include "Complex.h"

void printComplex(const Complex& c, const std::string& name) {
    std::cout << name << " = " << std::fixed << std::setprecision(2) 
              << c.re << " + " << c.im << "i" << std::endl;
}

int main() {
    std::cout << "=== ���������� ����������� ����� ===" << std::endl;
    std::cout << std::endl;
    
    // �������� ���� ����������� �����
    Complex a(3.0, 4.0);  // 3 + 4i
    Complex b(1.0, 2.0);  // 1 + 2i
    
    printComplex(a, "a");
    printComplex(b, "b");
    std::cout << std::endl;

    // ��������
    Complex sum = a + b;
    printComplex(sum, "a + b");
    
    // ���������
    Complex diff = a - b;
    printComplex(diff, "a - b");
    
    // ���������
    Complex product = a * b;
    printComplex(product, "a * b");
    
    // �������
    Complex quotient = a / b;
    printComplex(quotient, "a / b");
    
    std::cout << std::endl;
    
    // �������� ���� ����������� �����
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
    std::cout << "=== �������� ��� ��������������� ������� ===" << std::endl;

    // ������ ����������� �����, ������� �� ���� �������� ��������������� (������ ����� 0)
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
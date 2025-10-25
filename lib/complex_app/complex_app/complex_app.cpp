#include <iostream>
#include <iomanip>
#include <string>

struct ComplexManual {
    double re;
    double im;
};

// Вывод комплексного числа
void printComplex(const ComplexManual& c, const std::string& name) {
    std::cout << name << " = " << std::fixed << std::setprecision(2)
        << c.re << " + " << c.im << "i" << std::endl;
}

// Сложение
ComplexManual add(const ComplexManual& a, const ComplexManual& b) {
    return { a.re + b.re, a.im + b.im };
}

// Вычитание
ComplexManual subtract(const ComplexManual& a, const ComplexManual& b) {
    return { a.re - b.re, a.im - b.im };
}

// Умножение
ComplexManual multiply(const ComplexManual& a, const ComplexManual& b) {
    return { a.re * b.re - a.im * b.im,
            a.re * b.im + a.im * b.re };
}

// Деление
ComplexManual divide(const ComplexManual& a, const ComplexManual& b) {
    double denominator = b.re * b.re + b.im * b.im;
    return { (a.re * b.re + a.im * b.im) / denominator,
            (a.im * b.re - a.re * b.im) / denominator };
}

int main() {
    std::cout << "=== Арифметика комплексных чисел (без класса) ===" << std::endl << std::endl;

    ComplexManual a = { 3.0, 4.0 };
    ComplexManual b = { 1.0, 2.0 };

    printComplex(a, "a");
    printComplex(b, "b");
    std::cout << std::endl;

    printComplex(add(a, b), "a + b");
    printComplex(subtract(a, b), "a - b");
    printComplex(multiply(a, b), "a * b");
    printComplex(divide(a, b), "a / b");

    std::cout << std::endl;

    ComplexManual c = { 5.0, -3.0 };
    ComplexManual d = { 2.0, 1.0 };

    printComplex(c, "c");
    printComplex(d, "d");
    std::cout << std::endl;

    printComplex(add(c, d), "c + d");
    printComplex(subtract(c, d), "c - d");
    printComplex(multiply(c, d), "c * d");
    printComplex(divide(c, d), "c / d");

    std::cout << std::endl;
    std::cout << "=== Операции с действительными числами ===" << std::endl;

    ComplexManual real1 = { 7.0, 0.0 };
    ComplexManual real2 = { 3.0, 0.0 };

    printComplex(real1, "real1");
    printComplex(real2, "real2");
    std::cout << std::endl;

    printComplex(add(real1, real2), "real1 + real2");
    printComplex(subtract(real1, real2), "real1 - real2");
    printComplex(multiply(real1, real2), "real1 * real2");
    printComplex(divide(real1, real2), "real1 / real2");

    return 0;
}

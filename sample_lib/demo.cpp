#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <vector>

void printSeparator() {
    std::cout << std::string(50, '=') << std::endl;
}

void demonstrateBasicOperations() {
    std::cout << "Демонстрация основных операций с комплексными числами:" << std::endl;
    printSeparator();
    
    // Создание комплексных чисел
    Complex z1(3, 4);  // 3 + 4i
    Complex z2(1, -2); // 1 - 2i
    
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << std::endl;
    
    // Сложение
    Complex sum = z1 + z2;
    std::cout << "z1 + z2 = " << sum << std::endl;
    
    // Вычитание
    Complex diff = z1 - z2;
    std::cout << "z1 - z2 = " << diff << std::endl;
    
    // Умножение
    Complex prod = z1 * z2;
    std::cout << "z1 * z2 = " << prod << std::endl;
    
    // Деление
    Complex quot = z1 / z2;
    std::cout << "z1 / z2 = " << quot << std::endl;
    
    std::cout << std::endl;
}

void demonstrateProperties() {
    std::cout << "Демонстрация свойств комплексных чисел:" << std::endl;
    printSeparator();
    
    Complex z(3, 4);
    std::cout << "z = " << z << std::endl;
    std::cout << "Модуль |z| = " << z.magnitude() << std::endl;
    std::cout << "Аргумент arg(z) = " << z.phase() << " радиан" << std::endl;
    std::cout << "Аргумент arg(z) = " << z.phase() * 180.0 / 3.14159 << " градусов" << std::endl;
    std::cout << "Сопряженное z* = " << z.conjugate() << std::endl;
    std::cout << "Вещественная часть Re(z) = " << z.real() << std::endl;
    std::cout << "Мнимая часть Im(z) = " << z.imag() << std::endl;
    
    std::cout << std::endl;
}

void demonstrateAdvancedOperations() {
    std::cout << "Демонстрация расширенных операций:" << std::endl;
    printSeparator();
    
    Complex z(2, 1);
    std::cout << "z = " << z << std::endl;
    
    // Возведение в степень
    Complex z_squared = pow(z, 2);
    std::cout << "z^2 = " << z_squared << std::endl;
    
    // Квадратный корень
    Complex sqrt_z = sqrt(z);
    std::cout << "sqrt(z) = " << sqrt_z << std::endl;
    
    // Экспонента
    Complex exp_z = exp(z);
    std::cout << "exp(z) = " << exp_z << std::endl;
    
    // Логарифм
    Complex log_z = log(z);
    std::cout << "log(z) = " << log_z << std::endl;
    
    std::cout << std::endl;
}

void demonstrateComparison() {
    std::cout << "Демонстрация операций сравнения:" << std::endl;
    printSeparator();
    
    Complex z1(3, 4);
    Complex z2(3.0000001, 4.0000001);
    Complex z3(3, 5);
    
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "z3 = " << z3 << std::endl;
    std::cout << std::endl;
    
    std::cout << "z1 == z2: " << (z1 == z2 ? "true" : "false") << std::endl;
    std::cout << "z1 != z2: " << (z1 != z2 ? "true" : "false") << std::endl;
    std::cout << "z1 == z3: " << (z1 == z3 ? "true" : "false") << std::endl;
    std::cout << "z1 != z3: " << (z1 != z3 ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
}

void demonstrateAssignmentOperators() {
    std::cout << "Демонстрация операторов присваивания:" << std::endl;
    printSeparator();
    
    Complex z1(5, 3);
    Complex z2(2, 1);
    
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    
    // Операторы присваивания
    Complex z3 = z1;
    std::cout << "z3 = z1: " << z3 << std::endl;
    
    z3 += z2;
    std::cout << "z3 += z2: " << z3 << std::endl;
    
    z3 -= z2;
    std::cout << "z3 -= z2: " << z3 << std::endl;
    
    z3 *= z2;
    std::cout << "z3 *= z2: " << z3 << std::endl;
    
    z3 /= z2;
    std::cout << "z3 /= z2: " << z3 << std::endl;
    
    std::cout << std::endl;
}

void demonstrateErrorHandling() {
    std::cout << "Демонстрация обработки ошибок:" << std::endl;
    printSeparator();
    
    Complex z1(1, 1);
    Complex z2(0, 0);  // Нулевое комплексное число
    
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    
    try {
        Complex result = z1 / z2;
        std::cout << "z1 / z2 = " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Ошибка при делении: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(6);
    
    std::cout << "=== ДЕМОНСТРАЦИЯ БИБЛИОТЕКИ КОМПЛЕКСНЫХ ЧИСЕЛ ===" << std::endl;
    std::cout << std::endl;
    
    demonstrateBasicOperations();
    demonstrateProperties();
    demonstrateAdvancedOperations();
    demonstrateComparison();
    demonstrateAssignmentOperators();
    demonstrateErrorHandling();
    
    std::cout << "=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    
    return 0;
}
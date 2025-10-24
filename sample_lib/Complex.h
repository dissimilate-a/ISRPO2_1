#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
public:
    double re, im;
    
    // Конструкторы
    Complex(double real = 0, double imag = 0);
    Complex(const Complex& other);
    
    // Операторы арифметики
    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;
    
    // Операторы присваивания
    Complex& operator=(const Complex& rhs);
    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator/=(const Complex& rhs);
    
    // Операторы сравнения
    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    
    // Унарные операторы
    Complex operator-() const;
    Complex operator+() const;
    
    // Методы
    double magnitude() const;      // Модуль комплексного числа
    double phase() const;          // Аргумент комплексного числа
    Complex conjugate() const;     // Сопряженное число
    double real() const;           // Вещественная часть
    double imag() const;           // Мнимая часть
    
    // Дружественные функции для ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

// Внешние функции
Complex pow(const Complex& base, double exponent);
Complex sqrt(const Complex& c);
Complex exp(const Complex& c);
Complex log(const Complex& c);

#endif 

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    double re, im;
    Complex(double real = 0, double imag = 0);
    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;
};

#endif 

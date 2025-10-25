#include "Complex.h"

Complex::Complex(double real, double imag) : re(real), im(imag) {}

Complex Complex::operator+(const Complex& rhs) const {
    return Complex(re + rhs.re, im + rhs.im);
}

Complex Complex::operator-(const Complex& rhs) const {
    return Complex(re - rhs.re, im - rhs.im);
}

Complex Complex::operator*(const Complex& rhs) const {
    return Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
}

Complex Complex::operator/(const Complex& rhs) const {
    double d = rhs.re * rhs.re + rhs.im * rhs.im;
    return Complex((re * rhs.re + im * rhs.im) / d, (im * rhs.re - re * rhs.im) / d);
}

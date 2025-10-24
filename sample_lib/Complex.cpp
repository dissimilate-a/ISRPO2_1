#include "Complex.h"
#include <stdexcept>

// Конструкторы
Complex::Complex(double real, double imag) : re(real), im(imag) {}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

// Операторы арифметики
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
    if (d == 0) {
        throw std::runtime_error("Division by zero complex number");
    }
    return Complex((re * rhs.re + im * rhs.im) / d, (im * rhs.re - re * rhs.im) / d);
}

// Операторы присваивания
Complex& Complex::operator=(const Complex& rhs) {
    if (this != &rhs) {
        re = rhs.re;
        im = rhs.im;
    }
    return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    double new_re = re * rhs.re - im * rhs.im;
    double new_im = re * rhs.im + im * rhs.re;
    re = new_re;
    im = new_im;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    double d = rhs.re * rhs.re + rhs.im * rhs.im;
    if (d == 0) {
        throw std::runtime_error("Division by zero complex number");
    }
    double new_re = (re * rhs.re + im * rhs.im) / d;
    double new_im = (im * rhs.re - re * rhs.im) / d;
    re = new_re;
    im = new_im;
    return *this;
}

// Операторы сравнения
bool Complex::operator==(const Complex& rhs) const {
    const double epsilon = 1e-10;
    return std::abs(re - rhs.re) < epsilon && std::abs(im - rhs.im) < epsilon;
}

bool Complex::operator!=(const Complex& rhs) const {
    return !(*this == rhs);
}

// Унарные операторы
Complex Complex::operator-() const {
    return Complex(-re, -im);
}

Complex Complex::operator+() const {
    return *this;
}

// Методы
double Complex::magnitude() const {
    return std::sqrt(re * re + im * im);
}

double Complex::phase() const {
    return std::atan2(im, re);
}

Complex Complex::conjugate() const {
    return Complex(re, -im);
}

double Complex::real() const {
    return re;
}

double Complex::imag() const {
    return im;
}

// Дружественные функции для ввода/вывода
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.im >= 0) {
        os << c.re << " + " << c.im << "i";
    } else {
        os << c.re << " - " << -c.im << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.re >> c.im;
    return is;
}

// Внешние функции
Complex pow(const Complex& base, double exponent) {
    double magnitude = std::pow(base.magnitude(), exponent);
    double phase = base.phase() * exponent;
    return Complex(magnitude * std::cos(phase), magnitude * std::sin(phase));
}

Complex sqrt(const Complex& c) {
    double magnitude = std::sqrt(c.magnitude());
    double phase = c.phase() / 2.0;
    return Complex(magnitude * std::cos(phase), magnitude * std::sin(phase));
}

Complex exp(const Complex& c) {
    double exp_re = std::exp(c.re);
    return Complex(exp_re * std::cos(c.im), exp_re * std::sin(c.im));
}

Complex log(const Complex& c) {
    return Complex(std::log(c.magnitude()), c.phase());
}

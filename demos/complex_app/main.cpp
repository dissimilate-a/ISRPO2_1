#include <iostream>
#include "Complex.h"

int main() {
    Complex a(3, 4);
    Complex b(1, -2);

    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    std::cout << "a = (" << a.re << ", " << a.im << ")\n";
    std::cout << "b = (" << b.re << ", " << b.im << ")\n";
    std::cout << "a + b = (" << sum.re << ", " << sum.im << ")\n";
    std::cout << "a - b = (" << diff.re << ", " << diff.im << ")\n";
    std::cout << "a * b = (" << prod.re << ", " << prod.im << ")\n";
    std::cout << "a / b = (" << quot.re << ", " << quot.im << ")\n";

    return 0;
}

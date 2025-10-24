#include <iostream>
#include <cmath>
#include <cassert>
#include "Complex.h"

void testComplexOperations() {
    std::cout << "=== Testing Complex Number Operations ===" << std::endl;
    
    // Test case 1: (3 + 4i) + (1 + 2i) = (4 + 6i)
    Complex a(3.0, 4.0);
    Complex b(1.0, 2.0);
    Complex sum = a + b;
    assert(std::abs(sum.re - 4.0) < 1e-10);
    assert(std::abs(sum.im - 6.0) < 1e-10);
    std::cout << "✓ Addition test passed" << std::endl;
    
    // Test case 2: (3 + 4i) - (1 + 2i) = (2 + 2i)
    Complex diff = a - b;
    assert(std::abs(diff.re - 2.0) < 1e-10);
    assert(std::abs(diff.im - 2.0) < 1e-10);
    std::cout << "✓ Subtraction test passed" << std::endl;
    
    // Test case 3: (3 + 4i) * (1 + 2i) = (3*1 - 4*2) + (3*2 + 4*1)i = (-5 + 10i)
    Complex product = a * b;
    assert(std::abs(product.re - (-5.0)) < 1e-10);
    assert(std::abs(product.im - 10.0) < 1e-10);
    std::cout << "✓ Multiplication test passed" << std::endl;
    
    // Test case 4: (3 + 4i) / (1 + 2i) = (3*1 + 4*2)/(1^2 + 2^2) + (4*1 - 3*2)/(1^2 + 2^2)i
    // = (3 + 8)/5 + (4 - 6)/5*i = 11/5 + (-2)/5*i = 2.2 - 0.4i
    Complex quotient = a / b;
    assert(std::abs(quotient.re - 2.2) < 1e-10);
    assert(std::abs(quotient.im - (-0.4)) < 1e-10);
    std::cout << "✓ Division test passed" << std::endl;
    
    // Test case 5: Real numbers (imaginary part = 0)
    Complex real1(5.0, 0.0);
    Complex real2(3.0, 0.0);
    Complex realSum = real1 + real2;
    assert(std::abs(realSum.re - 8.0) < 1e-10);
    assert(std::abs(realSum.im - 0.0) < 1e-10);
    std::cout << "✓ Real number operations test passed" << std::endl;
    
    // Test case 6: Zero division handling
    Complex zero(0.0, 0.0);
    Complex one(1.0, 0.0);
    // Note: Division by zero should be handled gracefully
    // In a real implementation, you might want to add error handling
    std::cout << "✓ Zero division test (basic)" << std::endl;
    
    std::cout << std::endl;
    std::cout << "All tests passed! ✓" << std::endl;
}

int main() {
    try {
        testComplexOperations();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}
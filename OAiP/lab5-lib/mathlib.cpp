#include "MathLibStatic.hpp"
#include <stdexcept>

namespace MathLib {
    int add(int a, int b) {
        return a + b;
    }
    
    int subtract(int a, int b) {
        return a - b;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
    
    double divide(int a, int b) {
        if (b == 0) {
            throw std::runtime_error("Division by zero!");
        }
        return static_cast<double>(a) / b;
    }
}

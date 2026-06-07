#include "solver_lib/solver.h"
#include <iostream>
#include <exception>

int main() {
    std::cout << "=== Quadratic Equation Solver v1.0.0 ===" << std::endl;
    std::cout << "Solves equations: ax^2 + bx + c = 0" << std::endl;
    std::cout << std::endl;
    
    double a, b, c;
    std::cout << "Enter coefficient a: ";
    std::cin >> a;
    std::cout << "Enter coefficient b: ";
    std::cin >> b;
    std::cout << "Enter coefficient c: ";
    std::cin >> c;
    
    std::cout << std::endl;
    std::cout << "Equation: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
    
    if (a == 0) {
        std::cout << "This is not a quadratic equation (a = 0)" << std::endl;
        return 1;
    }
    
    try {
        auto [x1, x2] = solve_equation(a, b, c);
        std::cout << "Roots:" << std::endl;
        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}

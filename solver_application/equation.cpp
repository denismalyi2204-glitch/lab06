#include "formatter_ex.h"
#include <iostream>
#include <string>

int main() {
    std::string message = "Solver application started";
    std::string formatted = formatter_ex(message);
    std::cout << formatted << std::endl;
    
    // Здесь будет логика решения уравнения
    std::cout << "Enter equation to solve (format: ax^2+bx+c=0): " << std::endl;
    std::string equation;
    std::getline(std::cin, equation);
    
    return 0;
}

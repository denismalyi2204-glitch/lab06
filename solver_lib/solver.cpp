#include "solver.h"
#include <cmath>
#include <stdexcept>

std::pair<double, double> solve_equation(double a, double b, double c)
{
    double discriminant = b*b - 4*a*c;
    
    if (discriminant < 0) {
        throw std::runtime_error("No real roots");
    }
    
    double x1 = (-b + std::sqrt(discriminant)) / (2*a);
    double x2 = (-b - std::sqrt(discriminant)) / (2*a);
    
    return {x1, x2};
}

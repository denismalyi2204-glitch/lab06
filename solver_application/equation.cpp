#include <iostream>
#include "formatter_ex.h"
#include "solver.h"
int main() {
    float a, b, c;
    std::cin >> a >> b >> c;
    float x1, x2;
    try {
        solve(a, b, c, x1, x2);
        std::cout << format_ex("Equation entered: ") << a << " " << b << " " << c << std::endl;
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

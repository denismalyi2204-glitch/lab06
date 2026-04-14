#include "formatter_ex.h"

std::string formatter_ex(const std::string& message)
{
    std::string res = formatter(message);
    res += "Formatted with formatter_ex\n";
    return res;
}

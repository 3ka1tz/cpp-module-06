#include "ScalarConverter.hpp"

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    errno = 0;
    char *endptr;

    // ----------------------------------------------------
    // NAN, NANF
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";

        return;
    }

    // ----------------------------------------------------
    // +INF, +INFF
    if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";

        return;
    }

    // ----------------------------------------------------
    // -INF, -INFF
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";

        return;
    }

    // ----------------------------------------------------
    // CHAR
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        char c = literal[0];

        std::cout << "char: \'" << c << "\'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";

        return;
    }

    // ----------------------------------------------------
    // INT
    long int i = std::strtol(literal.c_str(), &endptr, 10);

    if (*endptr == '\0' && errno != ERANGE && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
    {
        if (i < 0 || i > 127)
        {
            std::cout << "char: impossible\n";
        }
        else if (!std::isprint(static_cast<unsigned char>(i)))
        {
            std::cout << "char: Non displayable\n";
        }
        else
        {
            std::cout << "char: \'" << static_cast<char>(i) << "\'\n";
        }
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";

        return;
    }

    // ----------------------------------------------------
    // FLOAT
    float f = std::strtof(literal.c_str(), &endptr);

    if ((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0' && errno != ERANGE)
    {
        if (f < 0 || f > 127)
        {
            std::cout << "char: impossible\n";
        }
        else if (!std::isprint(static_cast<unsigned char>(f)))
        {
            std::cout << "char: Non displayable\n";
        }
        else
        {
            std::cout << "char: \'" << static_cast<char>(f) << "\'\n";
        }
    }

    // ----------------------------------------------------
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

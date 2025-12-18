#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

void ScalarConverter::convert(const std::string& literal)
{
    // ---------------------------------------------------------------------------------------------
    // NAN, NANF
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: nanf\n"
                  << "double: nan\n";

        return;
    }

    // ---------------------------------------------------------------------------------------------
    // INF, INFF, +INF, +INFF
    if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: inff\n"
                  << "double: inf\n";

        return;
    }

    // ---------------------------------------------------------------------------------------------
    // -INF, -INFF
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: -inff\n"
                  << "double: -inf\n";

        return;
    }

    // ---------------------------------------------------------------------------------------------
    // CHAR
    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
    {
        char c = literal[0];

        std::cout << "char: \'" << c << "\'\n"
                  << "int: " << static_cast<int>(c) << "\n"
                  << "float: " << static_cast<float>(c) << "\n"
                  << "double: " << static_cast<double>(c) << "\n";

        return;
    }

    // ---------------------------------------------------------------------------------------------
    // INT
    char* endptr;
    errno = 0;
    long int i = std::strtol(literal.c_str(), &endptr, 10);

    if (*endptr == '\0' && errno != ERANGE && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
    {
        std::cout << "char: ";
        if (i < 0 || i > 127)
        {
            std::cout << "impossible" << std::endl;
        }
        else if (!std::isprint(static_cast<unsigned char>(i)))
        {
            std::cout << "Non displayable" << std::endl;
        }
        else
        {
            std::cout << "\'" << static_cast<char>(i) << "\'" << std::endl;
        }

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
    }

    // ---------------------------------------------------------------------------------------------
    // FLOAT
    errno = 0;
    float f = std::strtof(literal.c_str(), &endptr);

    if ((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0' && errno != ERANGE)
    {
        std::cout << "char: ";
        if (f < 0 || f > 127)
        {
            std::cout << "impossible" << std::endl;
        }
        else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(f))))
        {
            std::cout << "Non displayable" << std::endl;
        }
        else
        {
            std::cout << "\'" << static_cast<char>(f) << "\'" << std::endl;
        }

        std::cout << "int: ";
        if (f < static_cast<float>(std::numeric_limits<int>::min())
            || f > static_cast<float>(std::numeric_limits<int>::max()))
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            std::cout << static_cast<int>(f) << std::endl;
        }

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;

        return;
    }

    // ---------------------------------------------------------------------------------------------
    // DOUBLE
    errno = 0;
    double d = std::strtod(literal.c_str(), &endptr);

    if (*endptr == '\0' && errno != ERANGE)
    {
        std::cout << "char: ";
        if (d < 0 || d > 127)
        {
            std::cout << "impossible" << std::endl;
        }
        else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
        {
            std::cout << "Non displayable" << std::endl;
        }
        else
        {
            std::cout << "\'" << static_cast<char>(d) << "\'" << std::endl;
        }

        std::cout << "int: ";
        if (d < static_cast<double>(std::numeric_limits<int>::min())
            || d > static_cast<double>(std::numeric_limits<int>::max()))
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            std::cout << static_cast<int>(d) << std::endl;
        }

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

        return;
    }

    // ---------------------------------------------------------------------------------------------
    // INVALID INPUT
    else
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
    }
}

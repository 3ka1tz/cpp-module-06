#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum type {
    CHAR = 0,
    INT = 1,
    FLOAT = 2,
    DOUBLE = 3,
    POSITIVE_INF = 4,
    NEGATIVE_INF = 5,
    NANF = 6
};

class ScalarConverter {
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    type getType(const std::string& literal);

    static void convert(const std::string& literal);
};

#endif

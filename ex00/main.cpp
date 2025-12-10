#include "ScalarConverter.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return (1);
    }

    ScalarConverter::convert(argv[1]);
}

/*
Some Core Test Cases

    Char: 'a', 'Z', '0'

    Int: 0, 42, -42, +2147483647, -2147483648

    Float: 0.0f, 42.0f, -42.5f, 123456.789f

    Double: 0.0, 42.0, -42.5, 123456.789

    inf, inff, nan, nanf...
*/

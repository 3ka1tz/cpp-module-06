#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return EXIT_FAILURE;
    }

    ScalarConverter::convert(argv[1]);
}

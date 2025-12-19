#include "ScalarConverter.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << std::endl;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>\n" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    std::cout << std::endl;
}

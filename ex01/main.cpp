#include "Serializer.hpp"

#include <iostream>

int main() {
    Data d;

    d.id = 42;
    d.name = "Marvin";

    uintptr_t serialized = Serializer::serialize(&d);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << std::endl;

    std::cout << "    original_ptr: " << &d << std::endl;
    std::cout << "  serialized_ptr: " << serialized << std::endl;
    std::cout << "deserialized_ptr: " << deserialized << std::endl;

    std::cout << std::endl;
}

#include "Serializer.hpp"

#include <iostream>

int main() {
    Data d;
    d.id = 42;
    d.name = "Marvin";

    uintptr_t serialized = Serializer::serialize(&d);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "    original_ptr: " << &d << "\n"
              << "  serialized_ptr: " << serialized << "\n"
              << "deserialized_ptr: " << deserialized << std::endl;
}

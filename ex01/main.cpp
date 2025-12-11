#include "Serializer.hpp"

#include <iostream>

int main(void)
{
    Data d;
    d.name = "Marvin";
    d.age = 42;

    uintptr_t serialized = Serializer::serialize(&d);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "    original_ptr: " << &d << "\n"
              << "  serialized_ptr: " << serialized << "\n"
              << "deserialized_ptr: " << deserialized << "\n";

    return (0);
}

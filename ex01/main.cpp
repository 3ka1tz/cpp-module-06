#include "Serializer.hpp"

#include <iostream>

int main()
{
    Data sample;
    sample.name = "Alice";
    sample.age = 42;

    uintptr_t serialized = Serializer::serialize(&sample);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "    original_ptr: " << &sample << "\n"
              << "  serialized_ptr: " << serialized << "\n"
              << "deserialized_ptr: " << deserialized << "\n";
}

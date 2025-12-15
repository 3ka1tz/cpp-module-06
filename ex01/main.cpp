#include "Serializer.hpp"

#include <iostream>

int main() {
    Data sampleData;
    sampleData.name = "Marvin";
    sampleData.age = 42;

    uintptr_t serialized = Serializer::serialize(&sampleData);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "    original_ptr: " << &sampleData << "\n"
              << "  serialized_ptr: " << serialized << "\n"
              << "deserialized_ptr: " << deserialized << std::endl;
}

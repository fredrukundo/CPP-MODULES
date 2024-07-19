#include "Serializer.hpp"

#include <string>


int main()
{
    Data myData = {42, "Hello, World!"};
    uintptr_t  raw;

    std::cout << "Original pointer to Data struct: " << &myData << std::endl;
    raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer to Data struct: " << deserializedData << std::endl;

    if (deserializedData == &myData) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data contents: " << deserializedData->intValue << ", " << deserializedData->strValue << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }
    return 0;
}
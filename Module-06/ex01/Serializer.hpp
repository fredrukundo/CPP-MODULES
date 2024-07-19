#pragma once

#include <cstdint>
#include <iostream>

typedef struct t_data{
    int intValue;
    std::string strValue;

} Data;

class Serializer {

    private:
        Serializer();
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &src);
        ~Serializer();
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};
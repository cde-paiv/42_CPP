#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer {
    public:
        // converte ponteiro em inteiro
        static uintptr_t serialize(Data* ptr);

        // converte inteiro em ponteiro (endereco de memoria)
        static Data*    deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();
};
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
    try {
        Data *data = new Data(); 
        std::cout << "Print Data: " << std::endl;
        std::cout << data << std::endl; // imprime o endereco do ponteiro

        std::cout << "Print Serialized Data: " << std::endl;
        uintptr_t raw = Serializer::serialize(data); // ponteiro para inteiro
        std::cout << raw << std::endl; // imprime o inteiro

        std::cout << "Print Deserialized Data: " << std::endl;
        Data *data2 = Serializer::deserialize(raw); // inteiro para ponteiro
        std::cout << data2 << std::endl; // deve ser o mesmo endereco

        delete data;
    }
        catch (std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        return 0;
    }

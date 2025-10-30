#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "[AAnimal] default-constructed\n";
}

AAnimal::AAnimal(const std::string& t) : type(t)
{
    std::cout << "[AAnimal] constructed type=" << type << "\n";
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
    std::cout << "[AAnimal] copy-constructed\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "[AAnimal] copy-assigned\n";
    if (this != &other) type = other.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] destroyed\n";
}

std::string AAnimal::getType() const
{
    return type;
}

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "[Animal] default-constructed\n";
}

Animal::Animal(const std::string& t) : type(t)
{
    std::cout << "[Animal] constructed type=" << type << "\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "[Animal] copy-constructed\n";
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "[Animal] copy-assigned\n";
    if (this != &other) type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] destroyed\n";
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] *generic animal sound*\n";
}

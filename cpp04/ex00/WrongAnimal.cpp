#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "[WrongAnimal] default-constructed\n";
}

WrongAnimal::WrongAnimal(const std::string& t) : type(t)
{
    std::cout << "[WrongAnimal] constructed type=" << type << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "[WrongAnimal] copy-constructed\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "[WrongAnimal] copy-assigned\n";
    if (this != &other) type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] destroyed\n";
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] *wrong generic sound*\n";
}

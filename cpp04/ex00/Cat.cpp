#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] default-constructed (type=Cat)\n";
}

Cat::Cat(const std::string& nameType) : Animal(nameType)
{
    // ou Animal("Cat");
    std::cout << "[Cat] constructed type=" << type << "\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] copy-constructed\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[Cat] copy-assigned\n";
    if (this != &other) Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow!\n";
}

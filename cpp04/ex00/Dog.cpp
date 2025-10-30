#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "[Dog] default-constructed (type=Dog)\n";
}

Dog::Dog(const std::string& nameType) : Animal(nameType)
{
    std::cout << "[Dog] constructed type=" << type << "\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] copy-constructed\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] copy-assigned\n";
    if (this != &other) Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] destroyed\n";
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! \n";
}

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain())
{
    std::cout << "[Dog] constructed (type=Dog)\n";
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(0)
{
    std::cout << "[Dog] copy-constructed\n";
    _brain = other.getBrain() ? new Brain(*other.getBrain()) : new Brain();
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] copy-assigned\n";
    if (this != &other) {
        AAnimal::operator=(other);
        if (_brain) { delete _brain; _brain = 0; }
        _brain = other.getBrain() ? new Brain(*other.getBrain()) : new Brain();
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "[Dog] destroyed\n";
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof!\n";
}

Brain* Dog::getBrain()
{
    return _brain;
}

const Brain* Dog::getBrain() const
{
    return _brain;
}

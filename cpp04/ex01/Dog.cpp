#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "[Dog] constructed (type=Dog)\n";
}

Dog::Dog(const Dog& other) : Animal(other), _brain(0)
{
    std::cout << "[Dog] copy-constructed\n";
    // deep copy
    if (other._brain) {
        _brain = new Brain(*other._brain);
    } else {
        _brain = new Brain();
    }
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] copy-assigned\n";
    if (this != &other) {
        Animal::operator=(other);
        if (_brain) {
            delete _brain;
            _brain = 0;
        }
        _brain = other._brain ? new Brain(*other._brain) : new Brain();
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

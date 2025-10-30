#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "[Cat] constructed (type=Cat)\n";
}

Cat::Cat(const Cat& other) : Animal(other), _brain(0)
{
    std::cout << "[Cat] copy-constructed\n";
    if (other._brain) {
        _brain = new Brain(*other._brain);
    } else {
        _brain = new Brain();
    }
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[Cat] copy-assigned\n";
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

Cat::~Cat()
{
    delete _brain;
    std::cout << "[Cat] destroyed\n";
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow! \n";
}

Brain* Cat::getBrain()
{
    return _brain;
}
const Brain* Cat::getBrain() const { return _brain; }

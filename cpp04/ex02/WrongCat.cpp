#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[WrongCat] default-constructed (type=WrongCat)\n";
}

WrongCat::WrongCat(const std::string& nameType) : WrongAnimal(nameType)
{
    std::cout << "[WrongCat] constructed type=" << type << "\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] copy-constructed\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "[WrongCat] copy-assigned\n";
    if (this != &other) WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destroyed\n";
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] Meow? (but base is not virtual!)\n";
}

#pragma once
#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    explicit Cat(const std::string& nameType);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const; // override
};

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const std::string& nameType);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSound() const; // override
};

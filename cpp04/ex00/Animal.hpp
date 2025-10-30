#pragma once
#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    explicit Animal(const std::string& type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal(); // DEVE ser virtual!

    std::string getType() const;

    // polimorfismo: método virtual
    virtual void makeSound() const;

protected:
    std::string type; // acessível às derivadas
};

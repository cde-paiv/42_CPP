#pragma once
#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const std::string& type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal(); // virtual!

    std::string getType() const;
    virtual void makeSound() const; // polimórfico

protected:
    std::string type;
};

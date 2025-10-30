#pragma once
#include <iostream>
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    explicit WrongAnimal(const std::string& type);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    std::string getType() const;

    void makeSound() const;

protected:
    std::string type;
};
#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;

    Brain* getBrain();
    const Brain* getBrain() const;

private:
    Brain* _brain;
};

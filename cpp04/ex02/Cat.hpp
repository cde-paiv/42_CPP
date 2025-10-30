#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;

    Brain*       getBrain();
    const Brain* getBrain() const;

private:
    Brain* _brain;
};

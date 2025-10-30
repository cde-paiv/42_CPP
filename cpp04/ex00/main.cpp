#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Polymorphism OK (virtual) ===\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "j type: " << j->getType() << "\n";
    std::cout << "i type: " << i->getType() << "\n";

    i->makeSound();  // Cat sound
    j->makeSound();  // Dog sound
    meta->makeSound(); // generic Animal

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Polymorphism BROKEN (no virtual) ===\n";
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << "wc type: " << wc->getType() << "\n";

    wc->makeSound(); // Vai chamar WrongAnimal::makeSound() (som "errado")
    wa->makeSound(); // generic wrong animal

    delete wa;
    delete wc;

    std::cout << "\n=== Extra: array de Animal* (virtual funcionando) ===\n";
    const int N = 4;
    Animal* zoo[N];
    for (int k = 0; k < N; ++k)
        zoo[k] = (k % 2 == 0) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());

    for (int k = 0; k < N; ++k)
        zoo[k]->makeSound();

    for (int k = 0; k < N; ++k)
        delete zoo[k];

    return 0;
}

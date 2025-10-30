#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

int main() {
    std::cout << "=== ex02: AAnimal is ABSTRACT (pure virtual makeSound) ===\n";

    // Não pode instanciar AAnimal (classe abstrata):
    // AAnimal a;                 // <- erro de compilação, proposital
    // const AAnimal* p = new AAnimal(); // <- erro

    const int N = 4;
    AAnimal* zoo[N];

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) zoo[i] = new Dog();
        else            zoo[i] = new Cat();
    }

    std::cout << "\n=== Polymorphic sounds ===\n";
    for (int i = 0; i < N; ++i) {
        std::cout << zoo[i]->getType() << " -> ";
        zoo[i]->makeSound(); // despacho dinâmico para Dog/Cat
    }

    std::cout << "\n=== Deep Copy check (Dog) ===\n";
    Dog d1;
    d1.getBrain()->setIdea(0, "Chase the ball");
    Dog d2 = d1; // copy ctor (deep)
    std::cout << "d1[0]: " << d1.getBrain()->getIdea(0) << "\n";
    std::cout << "d2[0]: " << d2.getBrain()->getIdea(0) << "\n";
    d1.getBrain()->setIdea(0, "Eat");
    std::cout << "after d1 change, d1[0]: " << d1.getBrain()->getIdea(0) << "\n";
    std::cout << "d2 should remain, d2[0]: " << d2.getBrain()->getIdea(0) << "\n";

    std::cout << "\n=== Deep Copy check (Cat assignment) ===\n";
    Cat c1;
    c1.getBrain()->setIdea(1, "Sleep on keyboard");
    Cat c2;
    c2 = c1; // operator= (deep)
    c1.getBrain()->setIdea(1, "Knock mug off table");
    std::cout << "c1[1]: " << c1.getBrain()->getIdea(1) << "\n";
    std::cout << "c2 should remain, c2[1]: " << c2.getBrain()->getIdea(1) << "\n";

    for (int i = 0; i < N; ++i) delete zoo[i];

    return 0;
}

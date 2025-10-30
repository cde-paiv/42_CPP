#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Polymorphism with Brain (ex01) ===\n";
    const int N = 4;
    Animal* zoo[N];

    for (int i = 0; i < N; ++i) {
        zoo[i] = (i % 2 == 0) ? static_cast<Animal*>(new Dog()) : static_cast<Animal*>(new Cat());
    }

    for (int i = 0; i < N; ++i) {
        zoo[i]->makeSound();
    }

    // Teste: cópia profunda de Dog
    std::cout << "\n=== Deep Copy Test (Dog) ===\n";
    Dog d1;
    d1.getBrain()->setIdea(0, "Chase the ball");
    d1.getBrain()->setIdea(1, "Guard the house");

    Dog d2 = d1; // copy ctor (deep copy)
    std::cout << "d1 idea[0]: " << d1.getBrain()->getIdea(0) << "\n";
    std::cout << "d2 idea[0]: " << d2.getBrain()->getIdea(0) << "\n";

    // alterar d1 e mostrar que d2 não muda (prova de deep copy)
    d1.getBrain()->setIdea(0, "Eat");
    std::cout << "after change d1 idea[0]: " << d1.getBrain()->getIdea(0) << "\n";
    std::cout << "d2 idea[0] should remain: " << d2.getBrain()->getIdea(0) << "\n";

    // Teste: cópia profunda de Cat por assignment
    std::cout << "\n=== Deep Copy Test (Cat assignment) ===\n";
    Cat c1;
    c1.getBrain()->setIdea(0, "Sleep on keyboard");
    Cat c2;
    c2 = c1; // operator= (deep copy)
    c1.getBrain()->setIdea(0, "Knock things off the table");
    std::cout << "c1 idea[0]: " << c1.getBrain()->getIdea(0) << "\n";
    std::cout << "c2 idea[0] should remain: " << c2.getBrain()->getIdea(0) << "\n";

    for (int i = 0; i < N; ++i) delete zoo[i];

    return 0;
}

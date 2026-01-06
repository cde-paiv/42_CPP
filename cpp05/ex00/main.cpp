#include "Bureaucrat.hpp"

static void sep(const char* title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    sep("Valid constructions");
    try {
        Bureaucrat a;                    // Default (150)
        Bureaucrat b("Alice", 1);        // topo
        Bureaucrat c("Bob", 150);        // fundo
        std::cout << a << "\n" << b << "\n" << c << "\n";
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    sep("Invalid constructions");
    try {
        Bureaucrat x("X", 0);            // alto demais
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
    try {
        Bureaucrat y("Y", 151);          // baixo demais
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    sep("Increment/Decrement in range");
    try {
        Bureaucrat d("David", 3);
        std::cout << d << "\n";
        d.incrementGrade();              // 3 -> 2
        std::cout << d << "\n";
        d.decrementGrade();              // 2 -> 3
        std::cout << d << "\n";
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    sep("Increment out of range");
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << "\n";
        top.incrementGrade();            // deve lancar (ficaria 0)
        std::cout << top << "\n";        // nao chega aqui
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    sep("Decrement out of range");
    try {
        Bureaucrat low("Low", 150);
        std::cout << low << "\n";
        low.decrementGrade();            // deve lancar (ficaria 151)
        std::cout << low << "\n";        // nao chega aqui
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    sep("Copy & assignment");
    try {
        Bureaucrat m("Maria", 42);
        Bureaucrat n = m;                // copy ctor
        std::cout << m << "\n" << n << "\n";
        Bureaucrat p("Paulo", 100);
        p = m;                           // operator=
        std::cout << p << "\n";
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    return 0;
}
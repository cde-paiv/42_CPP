#include "Bureaucrat.hpp"
#include "Form.hpp"

static void sep(const char* title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    sep("Valid Form constructions");
    try {
        Form f1;                       // default (150/150)
        Form f2("TaxForm", 72, 45);    // sign 72, exec 45
        std::cout << f1 << "\n" << f2 << "\n";
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    sep("Invalid Form constructions");
    try {
        Form bad1("BadHigh", 0, 10);   // 0 é alto demais
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
    try {
        Form bad2("BadLow", 10, 151);  // 151 é baixo demais
    } catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    sep("Signing success");
    try {
        Bureaucrat alice("Alice", 40);
        Form permit("Permit", 50, 30); // precisa 50 p/ assinar
        std::cout << alice << "\n" << permit << "\n";
        alice.signForm(permit);        // 40 <= 50 → assina
        std::cout << permit << "\n";
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    sep("Signing failure");
    try {
        Bureaucrat bob("Bob", 80);
        Form tax("Tax", 50, 40);       // precisa 50 p/ assinar
        std::cout << bob << "\n" << tax << "\n";
        bob.signForm(tax);             // 80 > 50 → lança, catch em signForm
        std::cout << tax << "\n";
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    sep("Copy & Assignment of Form");
    try {
        Form a("A", 60, 60);
        Form b = a;                   // copy ctor
        std::cout << a << "\n" << b << "\n";
        Form c("C", 100, 100);
        c = a;                        // operator=
        std::cout << c << "\n";       // apenas signed pode mudar
    } catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << "\n";
    }

    return 0;
}

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void sep(const char* title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    sep("Construct bureaucrats");
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);
    Bureaucrat low("Low", 150);
    std::cout << boss << "\n" << mid << "\n" << low << "\n";

    sep("Shrubbery: sign & execute");
    {
        ShrubberyCreationForm f("home");
        std::cout << f << "\n";
        low.signForm(f);   // 150 <= 145 ? não, falha
        mid.signForm(f);   // 70  <= 145 ? ok, assina
        std::cout << f << "\n";
        low.executeForm(f); // 150 <= 137 ? não,  falha
        mid.executeForm(f); // 70  <= 137 ? ok, cria arquivo
    }

    sep("Robotomy: sign & execute");
    {
        RobotomyRequestForm f("Marvin");
        std::cout << f << "\n";
        mid.signForm(f);   // 70 <= 72 ? ok
        mid.executeForm(f);// 70 <= 45 ? não, falha
        boss.executeForm(f);// 1 <= 45 ? ok, 50% sucesso
    }

    sep("Pardon: sign & execute");
    {
        PresidentialPardonForm f("Arthur Dent");
        std::cout << f << "\n";
        mid.signForm(f);    // 70 <= 25 ? não, falha
        boss.signForm(f);   // 1  <= 25 ? ok
        mid.executeForm(f); // 70 <= 5  ? não, falha
        boss.executeForm(f);// 1  <= 5  ? ok, imprime perdão
    }

    return 0;
}

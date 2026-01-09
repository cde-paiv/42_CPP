#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

static void sep(const char* title) { std::cout << "\n===== " << title << " =====\n"; }

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);

    sep("Intern factory");
    Intern someRandomIntern;

    AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    // AForm* fX = someRandomIntern.makeForm("coffee please", "kitchen"); // inválido

    sep("Sign & Execute (when possible)");
    if (f1) {
        mid.signForm(*f1);    // 70 <= 72 ? ok (assina)
        mid.executeForm(*f1); // 70 <= 45 ? não
        boss.executeForm(*f1);// 1 <= 45 ? ok 50% robotomy
    }
    if (f2) {
        mid.signForm(*f2);    // 70 <= 145 ? ok
        mid.executeForm(*f2); // 70 <= 137 ? ok
    }
    if (f3) {
        mid.signForm(*f3);    // 70 <= 25 ? não
        boss.signForm(*f3);   // 1  <= 25 ? ok
        mid.executeForm(*f3); // 70 <= 5  ? não
        boss.executeForm(*f3);// 1  <= 5  ? ok imprime perdão
    }

    // liberar memória
    delete f1;
    delete f2;
    delete f3;
    // fX é NULL → nada a deletar

    return 0;
}

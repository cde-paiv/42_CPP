#include "Bureaucrat.hpp"

// ======= exceptions what() =======
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grade is too high (must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: garde is to low (must be <= 150)";
}

// ====== helpers =======
void    Bureaucrat::validateGrade(int g) const {
    if (g < 1)  throw GradeTooHighException();
    if (g > 150)    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "[Bureaucrat] default-constructed: " << _name
              << " (grade " << _grade << ")\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    validateGrade(_grade);
    std::cout << "[Bureaucrat] constructed: " << _name
              << " (grade " << _grade << ")\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "[Bureaucrat] copy-constructed: " << _name
              << "(grade " << _grade << ")\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "[Bureaucrat] copy-assigned\n";
    if (this != &other) {
        _grade = other._grade;
        validateGrade(_grade);
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "[Bureaucrat] destroyed: " << _name << "\n";
}

// ====== getters =======
const std::string& Bureaucrat::getname() const {return _name;}
int Bureaucrat::getgrade() const {return _grade;}

// ===== acoes ======
void    Bureaucrat::incrementGrade() {
    // melhora (numero menor e melhor)
    validateGrade(_grade - 1);
    _grade -= 1;
}

void    Bureaucrat::decrementGrade() {
    // piora (numero maior e pior)
    validateGrade(_grade + 1);
    _grade += 1;
}

// ======== operator<< =======
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getname() << ", bureaucrat grade " << b.getgrade();
    return os;
}
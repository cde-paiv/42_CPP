#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grade is too high (must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrta: grade is too low (must be <= 150)";
}

void    Bureaucrat::validateGrade(int g) const {
    if (g < 1) throw GradeTooHighException();
    if (g > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "[bureaucrat] default-cosntructed: " << _name
              << " (grade " << _grade << ")\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade) {
    validateGrade(_grade);
    std::cout << "[Bureaucrat] constructed: " << _name
              << "(grade " << _grade << ")\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade) {
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

// getters 
const std::string& Bureaucrat::getname() const {return _name; }
int Bureaucrat::getgrade() const {return _grade; }

// acoes
void    Bureaucrat::incrementGrade() { validateGrade(_grade - 1); _grade -= 1;}
void    Bureaucrat::decrementGrade() { validateGrade(_grade + 1); _grade += 1;}

// integracao com AForm
void    Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << getname() << " signed " << form.getname() << std::endl;
    } catch (std::exception& e) {
        std::cout << getname() << " couldn't sign " << form.getname()
                  << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << getname() << " executed " << form.getname() << std::endl;
    } catch (std::exception& e) {
        std::cout << getname() << " couldn't execute " << form.getname()
                  << " because " << e.what() << std::endl;
    }
}

// operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getname() << ", Bureaucrat grade " << b.getgrade() << ".";
    return os;
}
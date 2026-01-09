#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() { 
    std::cout << "[Intern] hired\n";
}

Intern::~Intern() { 
    std::cout << "[Intern] fired\n";
}

Intern::Intern(const Intern&) { 
    std::cout << "[Intern] copy-constructed\n";
}

Intern& Intern::operator=(const Intern&) {
    std::cout << "[Intern] copy-assigned\n";
    return *this;
}

// Helpers
static AForm* makeShrub(const std::string& target) { return new ShrubberyCreationForm(target); }
static AForm* makeRobo(const std::string& target)  { return new RobotomyRequestForm(target); }
static AForm* makePardon(const std::string& target){ return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*creators[3])(const std::string& target) = {
        &makeShrub, &makeRobo, &makePardon
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            AForm* f = creators[i](target);
            std::cout << "Intern creates " << f->getname() << " (target=\"" << f->getTarget() << "\")\n";
            return f;
        }
    }
    std::cout << "Intern: unknown form name \"" << formName << "\"\n";
    return NULL; // nome inválido
}

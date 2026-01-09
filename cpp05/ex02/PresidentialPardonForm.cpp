#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5, target) {
    std::cout << "[PresidentialPardonForm] constructed\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "[PresidentialPardonForm] destroyed\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other) {
    std::cout << "[PresidentialPardonForm] copy-constructed\n";
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "[PresidentialPardonForm] copy-assigned\n";
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void PresidentialPardonForm::doExecute() const {
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

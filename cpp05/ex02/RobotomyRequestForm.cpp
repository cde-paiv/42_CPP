#include "RobotomyRequestForm.hpp"
#include <cstdlib> // rand
#include <ctime> // time

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45, target) {
    std::cout << "[RobotomyRequestForm] constructed\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "[RobotomyRequestForm] destroyed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other) {
    std::cout << "[RobotomyRequestForm] copy-constructed\n";
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "[RobotomyRequestForm] copy-assigned\n";
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void    RobotomyRequestForm::doExecute() const {
    std::srand(static_cast<unsigned int>(std::time(0)));
    if (std::rand() % 2)
        std::cout << getTarget() << "has been robotomized successfully\n";
    else
        std::cout << "robotomy failed on " << getTarget() << ".\n";
}
#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        explicit RobotomyRequestForm(const std::string& target);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    protected:
        virtual void doExecute() const; // 50% sucesso/fracasso
};
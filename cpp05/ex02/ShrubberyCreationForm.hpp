#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        explicit ShrubberyCreationForm(const std::string& target);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    protected:
        virtual void    doExecute() const;
};


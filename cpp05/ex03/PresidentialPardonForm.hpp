#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    explicit PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

protected:
    virtual void doExecute() const; // imprime o perdao
};

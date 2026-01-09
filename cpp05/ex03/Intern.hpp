#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    // Cria um AForm* conforme o nome; retorna NULL se nome desconhecido
    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

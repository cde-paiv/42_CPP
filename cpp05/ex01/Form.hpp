#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // forward declaration

class Form {
public:
    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // === Torna tudo isto PÚBLICO ===
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters com nomes padronizados (CamelCase)
    const std::string& getname() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExec() const;

    // API pública para assinar
    void               beSigned(const Bureaucrat& b);

private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExec;

    void validateGrade(int g) const;
};

// operator<< declarado fora da classe
std::ostream& operator<<(std::ostream& os, const Form& f);

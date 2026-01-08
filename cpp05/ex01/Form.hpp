#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

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

    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    const std::string& getname() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExec() const;

    void               beSigned(const Bureaucrat& b);

private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExec;

    void validateGrade(int g) const;
};

// operator
std::ostream& operator<<(std::ostream& os, const Form& f);

#pragma once
#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public: virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public: virtual const char* what() const throw();
    };

    // OCF
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getname()  const;
    int                getgrade() const;

    // Acoes
    void incrementGrade();
    void decrementGrade();

    // Integracao AForm
    void signForm(AForm& form) const;
    void executeForm(AForm const& form) const;

private:
    const std::string _name;
    int               _grade;

    void validateGrade(int g) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

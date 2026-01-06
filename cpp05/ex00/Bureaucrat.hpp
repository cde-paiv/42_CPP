#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    public:
        class GradeTooHighException : public std::exception {
            public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
            virtual const char* what() const throw();
        };

        Bureaucrat(); // default
        Bureaucrat(const std::string& name, int grade); // com parametros
        Bureaucrat(const Bureaucrat& other); // copia
        Bureaucrat& operator=(const Bureaucrat& other); // atribuicao
        ~Bureaucrat(); // destrutor

        // getters
        const std::string& getname() const;
        int getgrade() const;

        // acoes
        void    incrementGrade(); // melhora 3 para 2
        void    decrementGrade();

    private:
        const std::string _name; // imutavel apos construcao
        int _grade;

        void validateGrade(int g) const; // centralizar a validacao
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
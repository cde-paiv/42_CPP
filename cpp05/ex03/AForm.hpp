#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception {
    public: virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public: virtual const char* what() const throw();
    };
    class NotSignedException : public std::exception {
    public: virtual const char* what() const throw();
    };

    // OCF
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Acesso
    const std::string& getname()        const;
    bool               isSigned()       const;
    int                getGradeToSign() const;
    int                getGradeToExec() const;
    const std::string& getTarget()      const;

    // Operacoes
    void beSigned(Bureaucrat const& b);
    void execute(Bureaucrat const& executor) const; // checa e chama doExecute()

protected:
    // Cada derivada implementa o passo concreto
    virtual void doExecute() const = 0;

private:
    const std::string _name;        // permanece na base
    bool              _isSigned;
    const int         _gradeToSign; // permanece na base
    const int         _gradeToExec; // permanece na base
    const std::string _target;      // alvo comum Forms

    void validateGrade(int g) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#include "Form.hpp"
#include "Bureaucrat.hpp"

// exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade is too high (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade is too low (must be <= 150)";
}

void    Form::validateGrade(int g) const {
    if (g < 1) throw GradeTooHighException();
    if (g > 150) throw GradeTooLowException();
}

Form::Form() : _name("DefaultForm"), _isSigned(false), 
_gradeToSign(150), _gradeToExec(150)
{
    std::cout << "[Form] default-constructed: " << _name
              << " (sign " << _gradeToSign << ", exec " << _gradeToExec << ")" << std::endl;
}

Form::Form(const std::string& name, int gs, int ge)
: _name(name), _isSigned(false), _gradeToSign(gs), _gradeToExec(ge)
{
    validateGrade(_gradeToSign);
    validateGrade(_gradeToExec);
    std::cout << "[Form] constructed: " << _name
              << "(sign " << _gradeToSign << ", exec " << _gradeToExec << ")" << std::endl;
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned),
_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "[Form] copy-constructed: " << _name << std::endl; 
}

Form& Form::operator=(const Form& other)
{
    std::cout << "[Form] copy-assigned" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "[Form] destroyed: " << _name << std::endl;
}

//getters
const std::string&  Form::getname() const    {return _name; }
bool                Form::isSigned() const   {return _isSigned; }
int                 Form::getGradeToExec() const    {return _gradeToExec; }
int                 Form::getGradeToSign() const    {return _gradeToSign; }

//assinatura
void    Form::beSigned(const Bureaucrat& b)
{
    // 1 e melhor que 2, alto suficiente para grade exigido
    if (b.getgrade() <= _gradeToSign) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getname() << "\" [signed="
       << (f.isSigned() ? "yes" : "no")
       << ", gradeToSign=" << f.getGradeToSign()
       << ", gradeToExec=" << f.getGradeToExec()
       << "]";
    return os;
}



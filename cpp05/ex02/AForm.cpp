#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: grade is too high (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: grade is too low (must be <= 150)";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm: form is not signed";
}

void    AForm::validateGrade(int g) const {
    if (g < 1)  throw GradeTooHighException();
    if (g > 150) throw GradeTooLowException();
}

AForm::AForm()
: _name("DefaultForm"), _isSigned(false),
  _gradeToSign(150), _gradeToExec(150), _target("default_target")
{
    std::cout << "[AForm] default-constructed: " << _name << std::endl;
}

AForm::AForm(const std::string& name, int gs, int ge, const std::string& target)
: _name(name), _isSigned(false), _gradeToSign(gs), _gradeToExec(ge), _target(target)
{
    validateGrade(_gradeToSign);
    validateGrade(_gradeToExec);
    std::cout << "[AForm] constructed: " << _name
              << " (sign " << _gradeToSign << ", exec " << _gradeToExec
              << ", target \"" << _target << "\")\n";
}

AForm::AForm(const AForm& other)
: _name(other._name), _isSigned(other._isSigned),
  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec),
  _target(other._target)
{
    std::cout << "[AForm] copy-constructed: " << _name << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "[AForm] copy-assigned\n";
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "[AForm] destroyed: " << _name << std::endl;
}

const std::string& AForm::getname()        const { return _name; }
bool               AForm::isSigned()       const { return _isSigned; }
int                AForm::getGradeToSign() const { return _gradeToSign; }
int                AForm::getGradeToExec() const { return _gradeToExec; }
const std::string& AForm::getTarget()      const { return _target; }

void AForm::beSigned(Bureaucrat const& b) {
    if (b.getgrade() <= _gradeToSign) _isSigned = true;
    else                              throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const {
    if (!isSigned())                 throw NotSignedException();
    if (executor.getgrade() > _gradeToExec) throw GradeTooLowException();
    doExecute(); // passou nas checagens, faz a ação concreta
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm \"" << f.getname() << "\" [signed="
       << (f.isSigned() ? "yes" : "no")
       << ", gradeToSign=" << f.getGradeToSign()
       << ", gradeToExec=" << f.getGradeToExec()
       << ", target=\"" << f.getTarget() << "\"]";
    return os;
}
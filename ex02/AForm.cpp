#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), 
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();

    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "Form name: " << f.getName() << ", Signed: " << (f.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << f.getGradeToSign()
        << ", Grade to execute: " << f.getGradeToExecute();
    return out;
}
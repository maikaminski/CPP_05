#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

static AForm *makeShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
static AForm *makeRobotomy(const std::string &target)  { return new RobotomyRequestForm(target); }
static AForm *makePardon(const std::string &target)    { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *(*makers[3])(const std::string &) = {
        makeShrubbery,
        makeRobotomy,
        makePardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return makers[i](target);
        }
    }
    std::cerr << "Intern: error: form '" << formName << "' does not exist" << std::endl;
    return NULL;
}

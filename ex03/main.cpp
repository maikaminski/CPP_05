#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Intern intern;

    std::cout << "\n=== Test 1: Intern creates ShrubberyCreationForm ===" << std::endl;
    AForm *shrub = intern.makeForm("shrubbery creation", "home");
    boss.signForm(*shrub);
    boss.executeForm(*shrub);
    delete shrub;

    std::cout << "\n=== Test 2: Intern creates RobotomyRequestForm ===" << std::endl;
    AForm *robot = intern.makeForm("robotomy request", "Bender");
    boss.signForm(*robot);
    boss.executeForm(*robot);
    delete robot;

    std::cout << "\n=== Test 3: Intern creates PresidentialPardonForm ===" << std::endl;
    AForm *pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    boss.signForm(*pardon);
    boss.executeForm(*pardon);
    delete pardon;

    std::cout << "\n=== Test 4: Intern tries unknown form ===" << std::endl;
    AForm *unknown = intern.makeForm("unknown form", "target");
    if (unknown)
        delete unknown;

    return 0;
}

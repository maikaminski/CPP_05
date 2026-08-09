#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);

    std::cout << "\n=== Test 1: ShrubberyCreationForm ===" << std::endl;
    ShrubberyCreationForm shrub("home");
    boss.signForm(shrub);
    boss.executeForm(shrub);

    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    RobotomyRequestForm robot("Bender");
    boss.signForm(robot);
    boss.executeForm(robot);

    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");
    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}
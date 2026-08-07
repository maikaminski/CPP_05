#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("default_target")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if(!file)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }
    file << "      /\\       " << std::endl;
    file << "     /~~\\      " << std::endl;
    file << "    /~~~~\\     " << std::endl;
    file << "   /~~~~~~\\    " << std::endl;
    file << "  /________\\   " << std::endl;
    file << "     /_\\       " << std::endl;
    file << "     /|\\       " << std::endl;
    file.close();
    std::cout << "Shrubbery created in file: " << _target + "_shrubbery" << std::endl;
}

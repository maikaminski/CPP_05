#include "Bureaucrat.hpp"

int main(void)
{
std::cout << "===== TEST: Grade too HIGH (constructor) =====" << std::endl;
try
{
std::cout << "Creating bureaucrat: Jorge (grade 0)" << std::endl;
Bureaucrat high("Jorge", 0);
}
catch (const std::exception &e)
{
std::cout << "Exception caught for Jorge: " << e.what() << std::endl;
}

std::cout << "\n===== TEST: Grade too LOW (constructor) =====" << std::endl;
try
{
    std::cout << "Creating bureaucrat: Biruleibe (grade 151)" << std::endl;
    Bureaucrat low("Biruleibe", 151);
}
catch (const std::exception &e)
{
    std::cout << "Exception caught for Biruleibe: " << e.what() << std::endl;
}

std::cout << "\n===== TEST: Valid bureaucrat =====" << std::endl;
try
{
    Bureaucrat valid("Maíra", 42);
    std::cout << "Created: " << valid << std::endl;

    std::cout << "\n-- Incrementing grade --" << std::endl;
    valid.incrementGrade();
    std::cout << valid << std::endl;

    std::cout << "\n-- Decrementing grade --" << std::endl;
    valid.decrementGrade();
    std::cout << valid << std::endl;
}
catch (const std::exception &e)
{
    std::cout << "Exception caught for Maíra: " << e.what() << std::endl;
}

std::cout << "\n===== TEST: Increment exception =====" << std::endl;
try
{
    Bureaucrat top("TopGuy", 1);
    std::cout << "Created: " << top << std::endl;

    std::cout << "Trying to increment TopGuy..." << std::endl;
    top.incrementGrade();
}
catch (const std::exception &e)
{
    std::cout << "Exception caught for TopGuy: " << e.what() << std::endl;
}

std::cout << "\n===== TEST: Decrement exception =====" << std::endl;
try
{
    Bureaucrat bottom("BottomGuy", 150);
    std::cout << "Created: " << bottom << std::endl;

    std::cout << "Trying to decrement BottomGuy..." << std::endl;
    bottom.decrementGrade();
}
catch (const std::exception &e)
{
    std::cout << "Exception caught for BottomGuy: " << e.what() << std::endl;
}

return 0;

}

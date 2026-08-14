#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "===== TESTE 1: criação válida =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 20);
        Form taxForm("Tax Form", 45, 30);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n===== TESTE 2: grade muito baixo pra assinar =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 100);
        Form contract("Contract", 50, 30);

        std::cout << alice << std::endl;
        std::cout << contract << std::endl;

        alice.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n===== TESTE 3: criação com grade inválido =====" << std::endl;
    try
    {
        Form invalidForm("Invalid", 0, 30);
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao criar Form: " << e.what() << std::endl;
    }

    std::cout << "\n===== TESTE 4: burocrata com grade inválido =====" << std::endl;
    try
    {
        Bureaucrat invalidBureaucrat("Evil", 200);
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao criar Bureaucrat: " << e.what() << std::endl;
    }

    std::cout << "\n===== TESTE 5: múltiplas assinaturas =====" << std::endl;
    try
    {
        Bureaucrat john("John", 20);
        Bureaucrat mike("Mike", 140);
        Form formA("FormA", 50, 50);

        std::cout << john << std::endl;
        std::cout << mike << std::endl;
        std::cout << formA << std::endl;

        mike.signForm(formA);
        john.signForm(formA);

        std::cout << formA << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << "Testing Grade too high" << std::endl;
	try {
		Bureaucrat high("Jorge", 0);
	} catch (const std::exception& e)
	{
		std::cout << "" << e.what() << '\n';
	}

	std::cout << '\n' << "Testing Grade too low" << std::endl;
	try {
		Bureaucrat low("Biruleibe", 151);
	} catch (const std::exception& e)
	{
		std::cout << "" << e.what() << '\n';
	}

	std::cout << '\n' << "Testing Grade correct" << std::endl;
	try {
		Bureaucrat grade("Maíra", 42);
	} catch (const std::exception& e)
	{
		std::cout << "" << e.what() << '\n';
	}
	return 0;
}

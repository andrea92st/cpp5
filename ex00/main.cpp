#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Jimmy("Jimmy", 42);
	Bureaucrat Juan("Juan", 1);
	Bureaucrat Joris("Joris", 150);

	std::cout << Jimmy << std::endl;
	std::cout << Juan << std::endl;
	std::cout << Joris << std::endl;

		
	std::cout << "Now lets try to build 2 bureaucraft with 0 & 151" << std::endl;
	try
	{
		Bureaucrat Jarvis("Jarvis", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Janvice("Janvice", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Now lets try to change grades of the 3 first" << std::endl;
	try
	{
		Juan.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Jimmy.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Joris.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "lets prints their grades now !" << std::endl;
	std::cout << Jimmy << std::endl;
	std::cout << Juan << std::endl;
	std::cout << Joris << std::endl;

	return 0;
}
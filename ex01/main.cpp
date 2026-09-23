#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"
 
int main()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	jimmy("Jimmy", 50);
	Bureaucrat	intern("Intern", 150);
	Form		contrat("Contrat", 50, 25);
 
	std::cout << boss << std::endl;
	std::cout << jimmy << std::endl;
	std::cout << intern << std::endl;
	std::cout << contrat << std::endl;
 
	std::cout << std::endl << "Forms avec grades invalides" << std::endl;
	try
	{
		Form bad("Bad", 0, 50);
		std::cout << bad << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form bad("Bad", 50, 151);
		std::cout << bad << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
 
	std::cout << std::endl << "Signature refusee" << std::endl;
	intern.signForm(contrat);
	std::cout << contrat << std::endl;
 
	std::cout << std::endl << "Signature pile au grade requis (50 vs 50)" << std::endl;
	jimmy.signForm(contrat);
	std::cout << contrat << std::endl;
 
	std::cout << std::endl << "Signature par un grade superieur" << std::endl;
	Form	permis("Permis", 10, 5);
	boss.signForm(permis);
	std::cout << permis << std::endl;
 
	return (0);
}
 

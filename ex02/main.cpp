#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	srand(time(NULL));

	std::cout << "===== 1. Creation des bureaucrates =====" << std::endl;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	middle("Middle", 70);
	Bureaucrat	intern("Intern", 150);

	std::cout << boss << std::endl;
	std::cout << middle << std::endl;
	std::cout << intern << std::endl;

	std::cout << std::endl << "===== 2. Creation des formulaires =====" << std::endl;
	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		robot("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << std::endl << "===== 3. Executer un formulaire NON SIGNE =====" << std::endl;
	boss.executeForm(shrub);

	std::cout << std::endl << "===== 4. Signatures =====" << std::endl;
	intern.signForm(shrub);
	boss.signForm(shrub); 
	intern.signForm(robot);
	middle.signForm(robot);
	middle.signForm(pardon);
	boss.signForm(pardon);

	std::cout << std::endl << "===== 5. Executions avec grade insuffisant =====" << std::endl;
	intern.executeForm(shrub);
	middle.executeForm(pardon);

	std::cout << std::endl << "===== 6. Executions valides =====" << std::endl;
	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	std::cout << std::endl << "===== 7. Robotomy x5 (50% de reussite) =====" << std::endl;
	for (int i = 0; i < 5; i++)
		boss.executeForm(robot);

	std::cout << std::endl << "===== 8. Polymorphisme via AForm* =====" << std::endl;
	AForm*	forms[3];

	forms[0] = new ShrubberyCreationForm("garden");
	forms[1] = new RobotomyRequestForm("Marvin");
	forms[2] = new PresidentialPardonForm("Ford Prefect");

	for (int i = 0; i < 3; i++)
	{
		boss.signForm(*forms[i]);
		boss.executeForm(*forms[i]);
		delete forms[i];
	}

	std::cout << std::endl << "===== 9. Grades invalides a la construction =====" << std::endl;
	try
	{
		ShrubberyCreationForm bad("x");
		std::cout << bad << std::endl;
		Bureaucrat ghost("Ghost", 0);
		std::cout << ghost << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return (*this);
}

void ShrubberyCreationForm::executeAction(void) const
{
    std::ofstream file((_target + "_shrubbery").c_str());

    if (!file.is_open())
    {
		std::cout << "Error: could not open file" << std::endl;
        return;
	}
    file << "      *      " << std::endl;
	file << "     ***     " << std::endl;
	file << "    *****    " << std::endl;
	file << "   *******   " << std::endl;
	file << "  *********  " << std::endl;
	file << "      |      " << std::endl;
	file << "      |      " << std::endl;
    file.close();
}
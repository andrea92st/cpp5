#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	_grade = src._grade;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if(this != &rhs)
		_grade = rhs._grade;
	return (*this);		
}

std::string const &Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
        throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{	
	if (_grade + 1 > 150)
        throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (o);
}

void Bureaucrat::signForm(Form & f) const
{
	try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << _name << " couldn't sign " << f.getName()
                  << " because " << e.what() << "." << std::endl;
    }
}
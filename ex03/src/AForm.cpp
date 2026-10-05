#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _grade_sign(150), _grade_exec(150)
{
}
	
AForm::AForm(std::string const & name, int gradeSign, int gradeExec) : _name(name), _signed(false), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
    	throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
    	throw GradeTooLowException();
}
	
AForm::~AForm()
{
}
AForm::AForm(AForm const & src): _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
        _signed = rhs._signed;
    return (*this);
}
    
bool	AForm::getSigned(void) const
{
	return(_signed);	
}

int		AForm::getGradeSign(void) const
{
	return(_grade_sign);
}

int		AForm::getGradeExec(void) const
{
	return(_grade_exec);
}

std::string const &AForm::getName(void) const
{
	return(_name);
}
	
void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _grade_sign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream & o, AForm const & rhs)
{
    o << "AForm " << rhs.getName()
      << ", signed: " << std::boolalpha << rhs.getSigned()
      << ", grade to sign: " << rhs.getGradeSign()
      << ", grade to execute: " << rhs.getGradeExec();
    return (o);
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low!");
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _grade_exec)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
    return ("Form is not signed");
}
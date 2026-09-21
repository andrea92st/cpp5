#include"Form.hpp"
#include"Bureaucrat.hpp"

Form::Form(void) : _name("default"), _signed(false), _grade_sign(150), _grade_exec(150)
{
}
	
Form::Form(std::string const & name, int gradeSign, int gradeExec) : _name(name), _signed(false), _grade_sign(gradeSign), _grade_exec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
    	throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
    	throw GradeTooLowException();
}
	
Form::~Form()
{
}
Form::Form(Form const & src): _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
        _signed = rhs._signed;
    return (*this);
}
    
bool	Form::getSigned(void) const
{
	return(_signed);	
}

int		Form::getGradeSign(void) const
{
	return(_grade_sign);
}

int		Form::getGradeExec(void) const
{
	return(_grade_exec);
}

std::string const &Form::getName(void) const
{
	return(_name);
}
	
void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _grade_sign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream & o, Form const & rhs)
{
    o << "Form " << rhs.getName()
      << ", signed: " << std::boolalpha << rhs.getSigned()
      << ", grade to sign: " << rhs.getGradeSign()
      << ", grade to execute: " << rhs.getGradeExec();
    return (o);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade is too low!");
}
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

	Form();
	Form(std::string const &name, int gradeSign, int gradeExec);
	~Form();
	Form(Form const &src);
	Form &operator=(Form const &rhs);
    
	bool	getSigned(void) const;
    int		getGradeSign(void) const;
    int		getGradeExec(void) const;
	std::string const &getName(void) const;
	void beSigned(Bureaucrat const &b);

	class GradeTooHighException : public std::exception
    {
    	public:
        	virtual const char* what(void) const throw();
    };
	class GradeTooLowException : public std::exception
    {
    	public:
        	virtual const char* what(void) const throw();
    };

	private:
		const std::string _name;
		bool _signed;
		const int _grade_sign;
		const int _grade_exec;
};

std::ostream &operator<<(std::ostream & o, Form const & rhs);

#endif
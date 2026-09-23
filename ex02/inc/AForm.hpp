#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:

	AForm();
	AForm(std::string const &name, int gradeSign, int gradeExec);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
    
	bool	getSigned(void) const;
    int		getGradeSign(void) const;
    int		getGradeExec(void) const;
	std::string const &getName(void) const;
	void beSigned(Bureaucrat const &b);

	void execute(Bureaucrat const & executor) const;
	virtual ~AForm();

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
	class FormNotSignedException : public std::exception
	{
		public:
    		virtual const char* what(void) const throw();
	};

	protected:
    	virtual void executeAction(void) const = 0;  
	
	private:
		const std::string _name;
		bool _signed;
		const int _grade_sign;
		const int _grade_exec;
};

std::ostream &operator<<(std::ostream & o, AForm const & rhs);

#endif
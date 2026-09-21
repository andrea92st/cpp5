#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form
{
	public:

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

#endif
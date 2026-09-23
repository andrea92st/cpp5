#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Form; 

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
   		Bureaucrat(Bureaucrat const &src);
    	~Bureaucrat(void);
    	Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string const &getName(void) const;
    	int getGrade(void) const;

    	void incrementGrade(void);
    	void decrementGrade(void);
		void signForm(Form & f) const; 

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
		std::string const	_name;
		int					_grade;
	
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(std::string const &target);
    Intern(Intern const &src);
    virtual ~Intern();
	AForm* makeForm(std::string const & formName, std::string const & target);
};

#endif
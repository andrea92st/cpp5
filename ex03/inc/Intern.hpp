#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & src);
        Intern & operator=(Intern const & rhs);
        ~Intern();

        AForm*  makeForm(std::string const & formName, std::string const & target) const;

    private:
        AForm*  createShrubbery(std::string const & target) const;
        AForm*  createRobotomy(std::string const & target) const;
        AForm*  createPresidential(std::string const & target) const;
};

#endif
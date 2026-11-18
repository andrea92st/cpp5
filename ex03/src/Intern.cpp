
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/* ===== Forme canonique (aucun attribut, donc rien à copier) ===== */

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
    (void)src;
}

Intern & Intern::operator=(Intern const & rhs)
{
    (void)rhs;
    return (*this);
}

Intern::~Intern()
{
}

/* ===== Les 3 "usines" privées : chacune crée un formulaire ===== */

AForm*  Intern::createShrubbery(std::string const & target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm*  Intern::createRobotomy(std::string const & target) const
{
    return (new RobotomyRequestForm(target));
}

AForm*  Intern::createPresidential(std::string const & target) const
{
    return (new PresidentialPardonForm(target));
}

/* ===== makeForm : tableau de noms <-> tableau de pointeurs sur méthodes ===== */

AForm*  Intern::makeForm(std::string const & formName, std::string const & target) const
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*creators[3])(std::string const &) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*creators[i])(target));
        }
    }
    std::cerr << "Intern error: form \"" << formName << "\" does not exist" << std::endl;
    return (NULL);
}
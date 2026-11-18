#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    srand(time(NULL));

    Bureaucrat  boss("Boss", 1);
    Bureaucrat  rookie("Rookie", 150);
    Intern      someRandomIntern;
    AForm*      f;

    std::cout << "===== 1. Exemple du sujet =====" << std::endl;
    f = someRandomIntern.makeForm("robotomy request", "Bender");
    if (f)
    {
        std::cout << *f << std::endl;
        boss.signForm(*f);
        boss.executeForm(*f);
        delete f;
    }

    std::cout << std::endl << "===== 2. Les 3 formulaires valides =====" << std::endl;
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++)
    {
        f = someRandomIntern.makeForm(names[i], "target");
        if (f)
        {
            boss.signForm(*f);
            boss.executeForm(*f);
            delete f;
        }
        std::cout << std::endl;
    }

    std::cout << "===== 3. Nom invalide =====" << std::endl;
    f = someRandomIntern.makeForm("coffee request", "Boss");
    if (f == NULL)
        std::cout << "-> NULL renvoye, rien a delete" << std::endl;
    else
        delete f;

    std::cout << std::endl << "===== 4. Nom presque bon (casse differente) =====" << std::endl;
    f = someRandomIntern.makeForm("Robotomy Request", "Marvin");
    if (f)
        delete f;

    std::cout << std::endl << "===== 5. Formulaire cree par le stagiaire, grade trop bas =====" << std::endl;
    f = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (f)
    {
        rookie.signForm(*f);     // echoue : 25 requis
        boss.signForm(*f);
        rookie.executeForm(*f);  // echoue : 5 requis
        boss.executeForm(*f);
        delete f;
    }

    std::cout << std::endl << "===== 6. Copie et affectation d'Intern (OCF) =====" << std::endl;
    Intern  copy(someRandomIntern);
    Intern  assigned;
    assigned = copy;
    f = assigned.makeForm("shrubbery creation", "garden");
    if (f)
        delete f;

    std::cout << std::endl << "===== 7. Grades invalides =====" << std::endl;
    try
    {
        Bureaucrat  ghost("Ghost", 0);
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat  ghost("Ghost", 151);
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}
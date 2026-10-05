#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm const & rhs);

protected:
    virtual void executeAction(void) const;

private:
    const std::string _target;
};

#endif
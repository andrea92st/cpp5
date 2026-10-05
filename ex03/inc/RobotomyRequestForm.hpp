#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);

protected:
    virtual void executeAction(void) const;

private:
    const std::string _target;
};

#endif
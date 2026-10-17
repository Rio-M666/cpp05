#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <iostream>

Intern::Intern()
{
}
Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target)
{
    const std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    typedef AForm* (Intern::*FormCreator)(const std::string&);
    const FormCreator creators[3] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    int i = 0;

    while (i < 3 && formName != forms[i])
        ++i;
    if (i == 3)
    {
        std::cout << "Form does not exist" << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << formName << std::endl;
    return (this->*creators[i])(target);
}

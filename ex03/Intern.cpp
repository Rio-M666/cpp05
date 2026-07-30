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

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target)
{
    const std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int i = 0;

    while (i < 3 && formName != forms[i])
        ++i;
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Form does not exist" << std::endl;
            return NULL;
    }
}

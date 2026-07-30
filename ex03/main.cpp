#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

static void testForm(Intern& intern, Bureaucrat& boss,
                     const std::string& formName,
                     const std::string& target)
{
    std::cout << "\n=== " << formName << " ===" << std::endl;

    AForm* form = intern.makeForm(formName, target);
    if (form == NULL)
    {
        std::cout << "No form was created." << std::endl;
        return;
    }

    std::cout << *form << std::endl;
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Intern intern;
    Bureaucrat boss("Boss", 1);

    testForm(intern, boss, "shrubbery creation", "garden");
    testForm(intern, boss, "robotomy request", "Bender");
    testForm(intern, boss, "presidential pardon", "Arthur Dent");
    testForm(intern, boss, "coffee request", "Evaluator");

    return 0;
}

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>

static void printTitle(const std::string& title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

static void testForm(Intern& intern, Bureaucrat& boss,
                     const std::string& formName,
                     const std::string& target)
{
    printTitle("Form creation: \"" + formName + "\"");

    AForm* form = intern.makeForm(formName, target);
    if (form == NULL)
    {
        std::cout << "No form was created." << std::endl;
        return;
    }

    std::cout << *form << std::endl;
    std::cout << "[sign successfully]" << std::endl;
    boss.signForm(*form);
    std::cout << *form << std::endl;
    std::cout << "[execute successfully]" << std::endl;
    boss.executeForm(*form);
    delete form;
}

static void testGradeBoundaries(Intern& intern, const std::string& formName,
                                const std::string& target)
{
    printTitle("Grade boundaries: " + formName);

    AForm* form = intern.makeForm(formName, target);
    if (form == NULL)
        return;

    Bureaucrat signer("Signer", form->getSignGrade());
    Bureaucrat weakSigner("Weak signer", form->getSignGrade() + 1);
    Bureaucrat executor("Executor", form->getExecuteGrade());
    Bureaucrat weakExecutor("Weak executor", form->getExecuteGrade() + 1);

    std::cout << *form << std::endl;

    std::cout << "[execute before signing]" << std::endl;
    executor.executeForm(*form);

    std::cout << "[sign with insufficient grade]" << std::endl;
    weakSigner.signForm(*form);
    std::cout << *form << std::endl;

    std::cout << "[sign at the required grade]" << std::endl;
    signer.signForm(*form);
    std::cout << *form << std::endl;

    std::cout << "[execute with insufficient grade]" << std::endl;
    weakExecutor.executeForm(*form);

    std::cout << "[execute at the required grade]" << std::endl;
    executor.executeForm(*form);
    delete form;
}

static void testIndependentForms(void)
{
    printTitle("Independent forms and targets");

    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* first = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm* second = intern.makeForm("presidential pardon", "Trillian");
    if (first == NULL || second == NULL)
    {
        delete first;
        delete second;
        return;
    }

    std::cout << "[sign only the first form]" << std::endl;
    boss.signForm(*first);
    std::cout << "First: " << *first << std::endl;
    std::cout << "Second: " << *second << std::endl;
    std::cout << "[execute the unsigned second form]" << std::endl;
    boss.executeForm(*second);

    std::cout << "[sign the second form and execute both targets]" << std::endl;
    boss.signForm(*second);
    boss.executeForm(*first);
    boss.executeForm(*second);
    delete first;
    delete second;
}

static void testCreation(void)
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    testForm(intern, boss, "shrubbery creation", "garden");
    testForm(intern, boss, "robotomy request", "Bender");
    testForm(intern, boss, "presidential pardon", "Arthur Dent");
}

static void testInvalidNames(void)
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    testForm(intern, boss, "coffee request", "Evaluator");
    testForm(intern, boss, "", "Empty name");
    testForm(intern, boss, "Robotomy request", "Wrong case");
    testForm(intern, boss, "presidential pardon ", "Trailing space");
}

static void testGradeBoundaries(void)
{
    Intern intern;

    testGradeBoundaries(intern, "shrubbery creation", "boundary_garden");
    testGradeBoundaries(intern, "robotomy request", "Marvin");
    testGradeBoundaries(intern, "presidential pardon", "Zaphod");
}

static void testCopy(void)
{
    printTitle("Copy and assignment");

    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "[create with a copy-constructed Intern]" << std::endl;
    Intern copied(intern);
    testForm(copied, boss, "presidential pardon", "Copied intern target");

    std::cout << "[create with a copy-assigned Intern]" << std::endl;
    Intern assigned;
    assigned = intern;
    testForm(assigned, boss, "robotomy request", "Assigned intern target");
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    try
    {
        testCreation();
        testInvalidNames();
        testGradeBoundaries();
        testIndependentForms();
        testCopy();
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

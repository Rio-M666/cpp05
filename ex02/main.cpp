#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>

static void printTitle(const std::string& title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

static void testForm(AForm& form)
{
    printTitle(form.getName());

    Bureaucrat signer("Signer", form.getSignGrade());
    Bureaucrat weakSigner("Weak signer", form.getSignGrade() + 1);
    Bureaucrat executor("Executor", form.getExecuteGrade());
    Bureaucrat weakExecutor("Weak executor", form.getExecuteGrade() + 1);

    std::cout << form << std::endl;

    std::cout << "[execute before signing]" << std::endl;
    executor.executeForm(form);

    std::cout << "[sign with insufficient grade]" << std::endl;
    weakSigner.signForm(form);
    std::cout << form << std::endl;

    std::cout << "[sign at the required grade]" << std::endl;
    signer.signForm(form);
    std::cout << form << std::endl;

    std::cout << "[execute with insufficient grade]" << std::endl;
    weakExecutor.executeForm(form);

    std::cout << "[execute at the required grade]" << std::endl;
    executor.executeForm(form);
}

static void testShrubbery(void)
{
    ShrubberyCreationForm form("garden");
    testForm(form);
}

static void testRobotomy(void)
{
    RobotomyRequestForm form("Bender");
    testForm(form);

    Bureaucrat executor("Executor", form.getExecuteGrade());
    std::cout << "[execute three more times to observe random outcomes]"
              << std::endl;
    for (int i = 0; i < 3; ++i)
        executor.executeForm(form);
}

static void testPresidentialPardon(void)
{
    PresidentialPardonForm form("Arthur Dent");
    testForm(form);
}

static void testCopy(void)
{
    printTitle("Copy and assignment");

    Bureaucrat boss("Boss", 1);
    PresidentialPardonForm original("Ford Prefect");

    boss.signForm(original);
    PresidentialPardonForm copied(original);
    PresidentialPardonForm assigned;
    assigned = original;

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copied  : " << copied << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    std::cout << "[execute copied and assigned forms]" << std::endl;
    boss.executeForm(copied);
    boss.executeForm(assigned);
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    try
    {
        testShrubbery();
        testRobotomy();
        testPresidentialPardon();
        testCopy();
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

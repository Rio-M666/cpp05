#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

static void printTitle(const std::string& title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

static void testShrubbery(void)
{
    printTitle("ShrubberyCreationForm");

    ShrubberyCreationForm form("garden");
    Bureaucrat signer("Shrubbery signer", 145);
    Bureaucrat weakSigner("Weak signer", 146);
    Bureaucrat executor("Shrubbery executor", 137);
    Bureaucrat weakExecutor("Weak executor", 138);

    std::cout << form << std::endl;

    std::cout << "[execute before signing]" << std::endl;
    executor.executeForm(form);

    std::cout << "[sign with insufficient grade]" << std::endl;
    weakSigner.signForm(form);

    std::cout << "[sign successfully]" << std::endl;
    signer.signForm(form);
    std::cout << form << std::endl;

    std::cout << "[execute with insufficient grade]" << std::endl;
    weakExecutor.executeForm(form);

    std::cout << "[execute successfully]" << std::endl;
    executor.executeForm(form);
}

static void testRobotomy(void)
{
    printTitle("RobotomyRequestForm");

    RobotomyRequestForm form("Bender");
    Bureaucrat signer("Robotomy signer", 72);
    Bureaucrat executor("Robotomy executor", 45);
    Bureaucrat weakExecutor("Weak executor", 46);

    std::cout << form << std::endl;

    std::cout << "[execute before signing]" << std::endl;
    executor.executeForm(form);

    std::cout << "[sign successfully]" << std::endl;
    signer.signForm(form);

    std::cout << "[execute with insufficient grade]" << std::endl;
    weakExecutor.executeForm(form);

    std::cout << "[execute four times to test 50% result]" << std::endl;
    for (int i = 0; i < 4; ++i)
        executor.executeForm(form);
}

static void testPresidentialPardon(void)
{
    printTitle("PresidentialPardonForm");

    PresidentialPardonForm form("Arthur Dent");
    Bureaucrat signer("Pardon signer", 25);
    Bureaucrat executor("President", 5);
    Bureaucrat weakExecutor("Minister", 6);

    std::cout << form << std::endl;

    std::cout << "[sign successfully]" << std::endl;
    signer.signForm(form);

    std::cout << "[execute with insufficient grade]" << std::endl;
    weakExecutor.executeForm(form);

    std::cout << "[execute successfully]" << std::endl;
    executor.executeForm(form);
}

static void testCopy(void)
{
    printTitle("Copy constructor");

    Bureaucrat president("President", 1);
    PresidentialPardonForm original("Ford Prefect");

    president.signForm(original);
    PresidentialPardonForm copied(original);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copied  : " << copied << std::endl;
    president.executeForm(copied);
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

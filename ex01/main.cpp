#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#include <iostream>
#include <string>

static void printTitle(const std::string& title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

static void testConstruction(void)
{
    printTitle("Valid construction");

    Bureaucrat chief("Chief", 1);
    Bureaucrat employee("Employee", 75);
    Form permit("Permit", 50, 25);

    std::cout << chief << std::endl;
    std::cout << employee << std::endl;
    std::cout << permit << std::endl;
}

static void testSigning(void)
{
    printTitle("Signing boundaries");

    Bureaucrat signer("Signer", 50);
    Bureaucrat weakSigner("Weak signer", 51);
    Form contract("Contract", 50, 20);

    std::cout << contract << std::endl;

    std::cout << "[sign with insufficient grade]" << std::endl;
    weakSigner.signForm(contract);
    std::cout << contract << std::endl;

    std::cout << "[sign at the required grade]" << std::endl;
    signer.signForm(contract);
    std::cout << contract << std::endl;
}

static void testInvalidGrades(void)
{
    printTitle("Invalid form grades");

    try
    {
        Form tooHigh("TooHigh", 0, 50);
        std::cout << "ERROR: grade 0 was accepted: " << tooHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        Form tooLow("TooLow", 50, 151);
        std::cout << "ERROR: grade 151 was accepted: " << tooLow << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
}

static void testCopy(void)
{
    printTitle("Copy and assignment");

    Bureaucrat signer("Signer", 1);
    Form original("Original", 10, 5);

    signer.signForm(original);
    Form copied(original);
    Form assigned;
    assigned = original;

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copied  : " << copied << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;
}

int main(void)
{
    try
    {
        testConstruction();
        testSigning();
        testInvalidGrades();
        testCopy();
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

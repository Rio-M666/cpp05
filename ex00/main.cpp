#include "Bureaucrat.hpp"

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
    Bureaucrat employee("Employee", 150);

    std::cout << chief << std::endl;
    std::cout << employee << std::endl;
}

static void testInvalidGrades(void)
{
    printTitle("Invalid bureaucrat grades");

    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << "ERROR: grade 0 was accepted: " << tooHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << "ERROR: grade 151 was accepted: " << tooLow << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
}

static void testGradeChanges(void)
{
    printTitle("Grade boundaries");

    Bureaucrat alice("Alice", 2);
    Bureaucrat bob("Bob", 149);

    std::cout << "[upgrade to grade 1]" << std::endl;
    std::cout << alice << std::endl;
    alice.upGrade();
    std::cout << alice << std::endl;

    std::cout << "[upgrade beyond grade 1]" << std::endl;
    try
    {
        alice.upGrade();
        std::cout << "ERROR: upgrade beyond grade 1 was accepted." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    std::cout << alice << std::endl;

    std::cout << "[downgrade to grade 150]" << std::endl;
    std::cout << bob << std::endl;
    bob.downGrade();
    std::cout << bob << std::endl;

    std::cout << "[downgrade beyond grade 150]" << std::endl;
    try
    {
        bob.downGrade();
        std::cout << "ERROR: downgrade beyond grade 150 was accepted." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    std::cout << bob << std::endl;
}

static void testCopy(void)
{
    printTitle("Copy and assignment");

    Bureaucrat original("Original", 42);
    Bureaucrat copied(original);
    Bureaucrat assigned;
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
        testInvalidGrades();
        testGradeChanges();
        testCopy();
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printTitle(const std::string& title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main(void)
{
    printTitle("Valid construction");
    try
    {
        Bureaucrat chief("Chief", 1);
        Bureaucrat employee("Employee", 75);
        Form permit("Permit", 50, 25);

        std::cout << chief << std::endl;
        std::cout << employee << std::endl;
        std::cout << permit << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    printTitle("Successful signing");
    try
    {
        Bureaucrat manager("Manager", 25);
        Form contract("Contract", 50, 20);

        std::cout << "Before: signed = "
                  << contract.getIsSigned() << std::endl;
        manager.signForm(contract);
        std::cout << "After : signed = "
                  << contract.getIsSigned() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    printTitle("Failed signing");
    try
    {
        Bureaucrat intern("Intern", 100);
        Form classified("Classified", 20, 10);

        intern.signForm(classified);
        std::cout << "Signed state: "
                  << classified.getIsSigned() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

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

    printTitle("Copy and assignment");
    try
    {
        Bureaucrat signer("Signer", 1);
        Form original("Original", 10, 5);

        signer.signForm(original);
        Form copied(original);
        Form assigned;
        assigned = original;

        std::cout << "Original signed: " << original.getIsSigned() << std::endl;
        std::cout << "Copied signed  : " << copied.getIsSigned() << std::endl;
        std::cout << "Assigned signed: " << assigned.getIsSigned() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}

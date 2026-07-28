#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include"ShrubberyCreationForm.hpp"

// static void printTitle(const std::string& title)
// {
//     std::cout << "\n=== " << title << " ===" << std::endl;
// }

int main(void)
{
    	Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
	ShrubberyCreationForm Shrubby_form("Hello");
	std::cout << std::endl;
	std::cout << Shrubby_form;
	Mr_Shrubby.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_Shrubby.executeForm(Shrubby_form);
    return 0;
}

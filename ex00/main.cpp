#include"Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat alice("Alice",2);

        std::cout<<alice<<std::endl;

        alice.upGrade();
        std::cout<<alice<<std::endl;

        alice.upGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr<<"Exception: " << e.what() << std::endl;
    }
    
     try
    {
        Bureaucrat invalid("Invalid", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 150);
        bob.downGrade(); 
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

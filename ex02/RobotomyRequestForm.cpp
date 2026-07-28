#include"RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():AForm("ShrubberyCreationForm",72,45),_target("Default")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target):AForm("ShrubberyCreationForm",72,45),_target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this!=&other)
        AForm::operator=(other);
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
void RobotomyRequestForm::executeAction() const
{
    std::cout<<"driiiiiriririiri"<<std::endl;

    if(std::rand()%2==0)
        std::cout<<_target<<" has been robotomized successfully"<<std::endl;
    else
        std::cout<<"Robotomy of "<<_target<<" faild"<<std::endl;
}

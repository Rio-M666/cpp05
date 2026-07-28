#include"PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("ShrubberyCreationForm",25,5),_target("Default")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("ShrubberyCreationForm",25,5),_target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other)
{
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this!=&other)
        AForm::operator=(other);
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
void PresidentialPardonForm::executeAction() const
{
    std::cout<<_target<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

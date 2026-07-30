#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm",145,137),_target("Default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("ShrubberyCreationForm",145,137),_target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other),_target(other._target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this!=&other)
    {
        AForm::operator=(other);
        _target=other._target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target+"_shrubbery").c_str());
    if(!file)
        throw std::runtime_error("Could not create shrubbery file");
    file << "       /\\\n"
         << "      /**\\\n"
         << "     /****\\\n"
         << "    /******\\\n"
         << "       ||\n";
}

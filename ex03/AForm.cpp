#include"AForm.hpp"
#include"Bureaucrat.hpp"

AForm::AForm():_name("Default"),_is_signed(false),_sign_grade(150),_execute_grade(150)
{    
}

AForm::AForm(const std::string& name,int sign_grade,int execute_grade):_name(name),_is_signed(false),_sign_grade(sign_grade),_execute_grade(execute_grade)
{
    if (_sign_grade < 1 || _execute_grade < 1)
        throw GradeTooHighException();
    if (_sign_grade > 150 || _execute_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other):_name(other._name),_is_signed(other._is_signed),_sign_grade(other._sign_grade),_execute_grade(other._execute_grade)
{
}

AForm &AForm::operator=(const AForm& other)
{
    if(this!=&other)
        _is_signed=other._is_signed;
    return(*this);
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade()<=_sign_grade)
        _is_signed=true;
    else
        throw GradeTooLowException();
}


std::string AForm::getName()const
{
    return(_name);
}
bool AForm::getIsSigned()const
{
    return(_is_signed);
}
int AForm::getSignGrade()const
{
    return(_sign_grade);
}
int AForm::getExecuteGrade()const
{
    return(_execute_grade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("AForm grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("AForm grade is too low");
}
void AForm::execute(const Bureaucrat& executor) const
{
    if (!_is_signed)
        throw FormNotSignedException();

    if (executor.getGrade() > _execute_grade)
        throw GradeTooLowException();

    executeAction();
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out,const AForm& AForm)
{
    out<<AForm.getName()<<", signed: "<<AForm.getIsSigned()<< ", sign grade: " << AForm.getSignGrade()
        << ", execute grade: " << AForm.getExecuteGrade();
    return out;
}

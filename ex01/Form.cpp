#include"Form.hpp"

Form::Form()
{    
}

Form::Form(std::string name,int sign_grade,int execute_grade)
{

}

Form::Form(const Form& other)
{
}

Form &Form::operator=(const Form& other)
{

}

Form::~Form()
{

}

void Form::beSigned(const Bureaucrat& bureaucrat)
{

}


std::string Form::getName()const
{
    return(_name);
}
bool Form::getIsSigned()const
{
    return(_is_signed);
}
int Form::getSignGrade()const
{
    return(_sign_grade);
}
int Form::getExecuteGrade()const
{
    return(_execute_grade);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Bureaucrat grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Bureaucrat grade is too low");
}

std::ostream& operator<<(std::ostream& out,const Bureaucrat& bureaucrat)
{
    out<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<".";
    return out;
}
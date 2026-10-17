#include"Form.hpp"
#include"Bureaucrat.hpp"

Form::Form():_name("Default"),_is_signed(false),_sign_grade(150),_execute_grade(150)
{    
}

Form::Form(const std::string name,int sign_grade,int execute_grade):_name(name),_is_signed(false),_sign_grade(sign_grade),_execute_grade(execute_grade)
{
    if(_sign_grade<1||_execute_grade<1)
        throw GradeTooHighException();
    if(_sign_grade>150||_execute_grade>150)
        throw GradeTooLowException();
}

Form::Form(const Form& other):_name(other._name),_is_signed(other._is_signed),_sign_grade(other._sign_grade),_execute_grade(other._execute_grade)
{
}

Form &Form::operator=(const Form& other)
{
    if(this!=&other)
        _is_signed=other._is_signed;
    return(*this);
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade()<=_sign_grade)
        _is_signed=true;
    else
        throw GradeTooLowException();
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
    return("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Form grade is too low");
}

std::ostream& operator<<(std::ostream& out,const Form& form)
{
    out<<form.getName()<<", signed: "<<form.getIsSigned()<< ", sign grade: " << form.getSignGrade()
        << ", execute grade: " << form.getExecuteGrade();
    return out;
}

#include "Bureaucrat.hpp"
#include"AForm.hpp"


Bureaucrat ::Bureaucrat():_name("Default"),_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name,int grade): _name(name), _grade(grade)
{
    if(grade<1)
        throw GradeTooHighException();
    if(grade>150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this!=&other)
        _grade=other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
    }
	std::cout << _name << " signed " << form.getName() << std::endl;

}

std::string Bureaucrat::getName()const
{
    return(_name);
}

int Bureaucrat::getGrade()const
{
    return(_grade);
}

void Bureaucrat::upGrade()
{
    if(_grade==1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::downGrade()
{
    if(_grade==150)
        throw GradeTooLowException();
    ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat grade is too low");
}

void Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed "<< form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't execute "<< form.getName()<< " because " << e.what()<< std::endl;
    }
}

std::ostream& operator<<(std::ostream& out,const Bureaucrat& bureaucrat)
{
    out<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<".";
    return out;
}


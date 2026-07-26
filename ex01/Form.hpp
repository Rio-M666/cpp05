#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>
#include<exception>

#include"Bureaucrat.hpp"

class Form
{
    private:
        std::string _name;
        bool _is_signed;
        int _sign_grade;
        int _execute_grade;
    public:
        Form();
        Form(std::string name,int sign_grade,int execute_grade);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

        void beSigned(const Bureaucrat& bureaucrat);

        std::string getName()const;
        bool getIsSigned()const;
        int getSignGrade()const;
        int getExecuteGrade()const;

        class GradeTooHighException:public std::exception
        {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException:public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out,const Form& form);

#endif
#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP


#include"AForm.hpp"
class PresidentialPardonForm:public AForm
{
    private:
        const std::string _target;
        virtual void executeAction() const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
};

#endif

#pragma once
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
		//Utils
		void	beSigned(Bureaucrat& buddy, std::string reason);
		void	execute(Bureaucrat const& executor) const;

		// Special Member Functions
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

    private:
        std::string	_target;

};

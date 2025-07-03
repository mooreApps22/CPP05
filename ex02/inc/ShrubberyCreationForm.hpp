#pragma once
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
		//Utils
		virtual void	beSigned(Bureaucrat& buddy, std::string reason);
		virtual void	execute(Bureaucrat const& executor) const;

		// Special Member Functions
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

    private:
        std::string	_target;

};

#pragma once
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
		//Utils
		void	beSigned(Bureaucrat& buddy);
		void	execute(Bureaucrat const& executor) const;

		// Special Member Functions
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

    private:
        std::string	_target;

};

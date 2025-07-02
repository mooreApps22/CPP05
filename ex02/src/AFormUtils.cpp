#include "AForm.hpp"
#include <iostream>
#include <string>

const std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::hasBeenSigned(void) const
{
	return (_isSigned);
}

int	AForm::gradeRequirement(void) const
{
	return (_gradeSignRequirement);
}
int	AForm::executionRequirement(void) const
{
	return (_gradeExecRequirement);
}

void	AForm::beSigned(Bureaucrat& buddy, std::string reason)
{
	std::cout << "Buddy's grade level: " << buddy.getGrade() << std::endl;
	try
	{
		std::cout << "Sign Grade Req: " << _gradeSignRequirement << std::endl;
		if (buddy.getGrade() > _gradeSignRequirement)
			throw BureaucratGradeTooLowException();
	}
	catch (const std::exception& err)
	{
		std::cerr << "\tEXECPTION CAUGHT: " << err.what() << std::endl;
		std::cout << buddy.getName() << " couldn't sign " << _name << " because " << reason << std::endl;
		return ;
	}
	_isSigned = true;
	std::cout << buddy.getName() << " signed " << _name << std::endl;
}


const char*	AForm::BureaucratGradeTooLowException::what() const throw()
{
	return ("This bureaucrat's grade level is not high enough!");
}

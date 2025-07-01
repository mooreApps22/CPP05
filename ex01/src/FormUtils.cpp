#include "Form.hpp"
#include <iostream>
#include <string>

const std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::hasBeenSigned(void) const
{
	return (_isSigned);
}

int	Form::gradeRequirement(void) const
{
	return (_gradeSignRequirement);
}
int	Form::executionRequirement(void) const
{
	return (_gradeExecRequirement);
}

void	Form::beSigned(Bureaucrat& buddy, std::string reason)
{
	try
	{
		if (buddy.getGrade() > _gradeSignRequirement)
			throw BureaucratGradeTooLowException();
	}
	catch (const std::exception& err)
	{
		std::cerr << "EXECPTION CAUGHT: " << err.what() << std::endl;
		std::cout << buddy.getName() << " couldn't sign " << _name << " because " << reason << std::endl;
		return ;
	}
	_isSigned = true;
	std::cout << buddy.getName() << " signed " << _name << std::endl;
}


const char*	Form::BureaucratGradeTooLowException::what() const throw()
{
	return ("This bureaucrat's grade level is not high enough!");
}

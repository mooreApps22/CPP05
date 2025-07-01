#include "../inc/Form.hpp"

/*
		Operator Overload:
			<< must print all the forms informations
*/


const std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::hasBeenSigned(void) const
{
	return (_isSigned);
}
		 
const int	Form::signGradeRequired(void) const
{
	return (_gradeSignRequirement);
}

const int	Form::execGradeRequired(void) const
{
	return (_gradeExecRequirement);
}

void	Form::beSigned(Bureaucrat& buddy)
{
	if (_isSigned)
	{
		std::cout << _name << " has already been signed, " << buddy->getName();
		return ;
	}
	if (buddy.getGrade() > _gradeSignRequirement)
		throw gradeTooLowException();
	_isSigned = true;
}

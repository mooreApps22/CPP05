#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	Bureaucrat::signForm(AForm& paper)
{
	paper.beSigned(*this, ""); // A machanism for selecting the correct reason would be good
}

void	Bureaucrat::incrementGrade(void) // <--lowers grade 3 to grade 2
{
	if (_grade <= 1)
	{
		throw GradeTooHighException();
		return ;
	}
	_grade--;
	std::cout << "was demoted.";
}

void	Bureaucrat::decrementGrade(void) // <--raises grade 2 to grade 3
{
	if (_grade >= 150)
	{
		throw GradeTooLowException();
		return ;
	}
	_grade++;
	std::cout << "was promoted.";
}

std::string		Bureaucrat::getName(void) const
{
	return (_name);	
}

int		Bureaucrat::getGrade(void) const
{
	return (_grade);	
}

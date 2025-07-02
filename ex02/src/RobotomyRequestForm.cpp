#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/*
*/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other._target)
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->AForm::hasBeenSigned())
		throw std::runtime_error("Form not signed, can't execute.");
	
	if (executor.getGrade() > this->AForm::executionRequirement())
		throw AForm::GradeTooLowException();
	std::cout << "* DRILL NOISES * " << _target << " has been robotomized ";
	std::srand(std::time(0));
	std::cout <<  ((rand() % 2 == 0) ? "successfully!" : "unsuccessfully.") << std::endl;
}

void	RobotomyRequestForm::beSigned(Bureaucrat& buddy)
{
	std::cout << std::endl << "Attempting to sign Robotomy Form" << std::endl;
	AForm::beSigned(buddy, " you must be grade 72 to sign and 45 to execute.");
}

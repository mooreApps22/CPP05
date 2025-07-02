#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*
			required grade: sign 25, exec 5 
						<target> has been pardoned by Zphod Beedblebrox	
*/

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other._target)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->AForm::hasBeenSigned())
		throw std::runtime_error("Form not signed, can't execute.");
	
	if (executor.getGrade() > this->AForm::executionRequirement())
		throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zphod Beedblebrox." << std::endl; 	
}

void	PresidentialPardonForm::beSigned(Bureaucrat& buddy)
{
	std::cout << std::endl << "Attempting to sign Presidential Pardon Form... " << std::endl;
	AForm::beSigned(buddy, " you must be grade 25 to sign and 5 to execute.");
}


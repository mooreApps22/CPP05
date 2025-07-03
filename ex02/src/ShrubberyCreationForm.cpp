#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other._target)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->AForm::hasBeenSigned())
		throw std::runtime_error("Form not signed, can't execute.");
	if (executor.getGrade() > this->AForm::executionRequirement())
		throw AForm::GradeTooLowException();
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("File creation failed");
	
	ofs << "   x" << std::endl;
	ofs << "  xxx" << std::endl;
	ofs << " xxxxx " << std::endl;
	ofs << "   x   " << std::endl;
	ofs << "       " << std::endl;
	ofs << "   x" << std::endl;
	ofs << "  xxx" << std::endl;
	ofs << " xxxxx " << std::endl;
	ofs << "   x   " << std::endl;
	ofs << "       " << std::endl;
	ofs << "   x" << std::endl;
	ofs << "  xxx" << std::endl;
	ofs << " xxxxx " << std::endl;
	ofs << "   x   " << std::endl;
	ofs.close();
}

void	ShrubberyCreationForm::beSigned(Bureaucrat& buddy, std::string reason)
{
	(void)reason;

	std::cout << std::endl << "Attempting to sign Shrubbery Creation Form... " << std::endl;
	AForm::beSigned(buddy, " you must be grade 147 to sign and 137 to execute.");
}


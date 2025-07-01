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
	if (!this->hasBeenSigned())
		throw std::runtime_error("Form not signed");
	
	if (executor.getGrade() > this->executionRequirement())
		throw AForm::GradeTooLowException();
	
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("File creation failed");
	
	ofs << " x" << std::endl;
	ofs << "xxx" << std::endl;
	ofs << " x " << std::endl;
	ofs << "xxx" << std::endl;
	ofs << " x " << std::endl;
	ofs << "xxx" << std::endl;
	ofs << " x " << std::endl;
	ofs.close();
}

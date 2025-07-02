#include "AForm.hpp"

AForm::AForm() :
	_name("F1"),
	_isSigned(false),
	_gradeSignRequirement(75),
	_gradeExecRequirement(75)
{}

AForm::AForm(const std::string& name, const int gradeSignReq, const int gradeExecReq) :
	_name(name),
	_isSigned(false),
	_gradeSignRequirement(gradeSignReq),
	_gradeExecRequirement(gradeExecReq)
{
	if (gradeSignReq > 150)
		throw GradeTooLowException();
	if (gradeSignReq < 1)
		throw GradeTooHighException();
	if (gradeExecReq > 150)
		throw GradeTooLowException();
	if (gradeExecReq < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(false),
	_gradeSignRequirement(other._gradeSignRequirement),
	_gradeExecRequirement(other._gradeExecRequirement)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other) 
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("A Form grade cannot be lower than 150!");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("A Form grade cannot be higher than 1!");
}

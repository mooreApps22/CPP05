#include "../inc/Form.hpp"

Form::Form() :
	_name("F1"),
	_isSigned(false),
	_gradeSignRequirement(75),
	_gradeExecRequirement(75)
{}

Form::Form(const std::string& name, const int gradeSignReq, const int gradeExecReq) :
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

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(false),
	_gradeSignRequirement(other._gradeSignRequirement),
	_gradeExecRequirement(other._gradeExecRequirement)
{
	*this = other;
}

Form& Form::operator=(const Form& other) 
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade cannot be lower than 150!");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade cannot be higher than 1!");
}

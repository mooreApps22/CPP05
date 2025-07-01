#include "../inc/Form.hpp"

Form::Form() :
	_name("F1-B1"),
	_isSigned(false),
	_gradeSignRequirement(75),
	_gradeExecRequirement(75)
{}

Form::Form(const std::string& name, const int gradeSignReq, const int gradeExecReq) : 
	_name(name),
	_isSigned(false)
{
	if (gradeSignReq >= 150)
		throw GradeToLowException();
	if (gradeExecReq >= 150)
		throw GradeToLowException();
	if (gradeSignReq < 1)
		throw GradeToHighException();
	if (gradeExecReq < 1)
		throw GradeToHighException();
	_gradeSignRequirement = gradeSignReq;
	_gradeExecRequirement = gradeExecReq;
}

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(false),
	_(other._gradeSignRequirement),
	_(other._gradeExecRequirement)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_gradeSignRequirement = other._gradeSignRequirement;
		this->_gradeExecRequirement = other._gradeExecRequirement;
	}
	return (*this);
}

Form::~Form() {}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("There isn't a Bureaucrat Grade lower than 150.");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("There isn't a Bureaucrat Grade higher than 1.");
}

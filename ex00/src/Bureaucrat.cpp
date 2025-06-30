#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bernie Sanders"), _grade(50) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("A bureaucrat's grade cannot be higher than Grade 1");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("A bureaucrat's grade cannot be lower than Grade 150");
}

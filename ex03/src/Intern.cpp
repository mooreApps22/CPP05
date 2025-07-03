#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string> 
#include <iostream> 
#include <map> 

Intern::Intern()
{
	_forms["shrubbery creation"]	= &Intern::_scf;
	_forms["robotomy request"]		= &Intern::_rrf;
	_forms["presidential pardon"]	= &Intern::_ppf;
}

Intern::Intern(const Intern& other) {*this = other;}
Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		_forms = other._forms;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::_scf(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_rrf(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_ppf(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	InternForms::iterator it = _forms.find(formName);

	if (it != _forms.end())
		return (this->* (it->second))(target);
	else
	{
		std::cerr << "\tThe intern doesn't know that form. The available forms are:" << std::endl;
		std::cerr << "\t\tshrubbery creation" << std::endl;
		std::cerr << "\t\trobotomy request" << std::endl;
		std::cerr << "\t\tpresidential pardon" << std::endl;
		return (NULL);
	}
}

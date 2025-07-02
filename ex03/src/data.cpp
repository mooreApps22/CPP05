#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream& operator<<(std::ostream& out, const Bureaucrat& buddy)
{
	out << std::endl;

	out << buddy.getName() << ", bureaucrat grade " << buddy.getGrade() << std::endl;
	return (out);
}

std::ostream& operator<<(std::ostream& out, const AForm& paper)
{
	out << std::endl;

	out << "This is form ";
	out << paper.getName();
	out << ". Bureaucrats need to be grade ";
	out << paper.gradeRequirement();
	out << " to sign it and ";
	out << paper.executionRequirement();
	out << " to execute it." << std::endl;
	if (paper.hasBeenSigned())
		out << paper.getName() << " form has been signed.";
	else
		out << paper.getName() << " form has not been signed.";
	out << std::endl;
	return (out);
}

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& out, const Bureaucrat& buddy)
{
	out << buddy.getName() << ", bureaucrat grade " << buddy.getGrade() << std::endl;
	return (out);
}

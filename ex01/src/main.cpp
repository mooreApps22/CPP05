#include <iostream>
#include "data.hpp" 
#include "Bureaucrat.hpp" 

int	main(void)
{
	Bureaucrat	b1;
	int			grade;
	std::string	name;	

	std::cout << "Enter a name: ";
	std::cin >> name;
	std::cout << "Enter a grade: ";
	std::cin >> grade;

	try
	{
		Bureaucrat tmp(name, grade);	
		b1 = tmp;
	}
	catch (const std::exception& e)
	{
		std::cerr << "EXCEPTION CAUGHT: " << e.what() << std::endl;
		return (1);
	}
	std::cout << b1;
	try 
	{
		for (int i = 0; i < 77; i++)
		{
			b1.decrementGrade();
			std::cout << b1;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "EXCEPTION CAUGHT: " << e.what() << std::endl;
	}
	return (0);
}

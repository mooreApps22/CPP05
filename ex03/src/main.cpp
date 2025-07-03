#include <iostream>
#include "data.hpp" 
#include "Bureaucrat.hpp" 
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp" 
#include "PresidentialPardonForm.hpp" 
#include "Intern.hpp"
#include <limits>

void	setupSimulation(Bureaucrat*& b1, AForm*& f1, Intern*& intern)
{
	while (true)
	{
		std::string	name;	
		int			grade;

		std::cout << std::endl;
		std::cout << "Enter a Bureaucrat name: ";
		std::cin >> name;
		std::cout << "Enter a Bureaucrat grade: ";
		std::cin >> grade;

		std::string	target;	

		std::cout << "Enter a targets name: ";
		std::cin >> target;

		std::string formName;

		std::cout << "Enter a form name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, formName);
		std::cout << "\nYou entered the form name: " << formName << std::endl;

		try
		{
			b1 = new Bureaucrat(name, grade);
			f1 = intern->makeForm(formName, target);	
			if (!f1)
			{
				std::cerr << "\tThe intern can't find whatever file you entered." << std::endl;
				delete b1;
				b1 = NULL;
				continue ;
			}
			break ;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "\tEXCEPTION CAUGHT: " << ex.what() << std::endl;
			continue ;
		}
	}

	std::cout << *b1;
	std::cout << *f1;
}

void runSimulation(Bureaucrat*& b1, AForm*& f1)
{
	try 
	{
		b1->signForm(*f1);
		f1->execute(*b1);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "\tEXCEPTION CAUGHT: " << ex.what() << std::endl;
	}
	std::cout << *b1;
	std::cout << *f1;
}

int	main(void)
{
	Bureaucrat*	b1 = NULL;
	AForm*		f1 = NULL;
	Intern*		intern = new Intern();

	setupSimulation(b1, f1, intern);
	runSimulation(b1, f1);

	std::cout << *b1;
	std::cout << *f1;

	delete b1;
	delete f1;
	delete intern;

	return (0);
}

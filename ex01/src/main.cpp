#include <iostream>
#include "data.hpp" 
#include "Bureaucrat.hpp" 
#include "Form.hpp" 

void	setup(Bureaucrat*& b1, Form*& f1)
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

		int			signGrade;
		std::string	formName;

		std::cout << "Enter a Form name: ";
		std::cin >> formName;
		std::cout << "Enter the grade needed to sign this form: ";
		std::cin >> signGrade;
		std::cout << std::endl;
		
		try
		{
			b1 = new Bureaucrat(name, grade);
			f1 = new Form(formName, signGrade, 75);	
			break ;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "EXCEPTION CAUGHT: " << ex.what() << std::endl;
			continue ;
		}
	}

	std::cout << *b1;
	std::cout << *f1;
}

int	main(void)
{
	Bureaucrat*	b1 = NULL;
	Form*		f1 = NULL;

	setup(b1, f1);

	
	try 
	{
		b1->signForm(*f1);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "EXCEPTION CAUGHT: " << ex.what() << std::endl;
	}
	std::cout << *f1;

	delete b1;
	delete f1;

	return (0);
}

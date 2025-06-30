#pragma once
# include <iostream>

class Bureaucrat
{
    private:
        const std::string	_name;
		unsigned int		_grade;
    public:
        Bureaucrat(const std::string& name, unsigned int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

		class GradeTooHighException : public std::exception // under 1
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception // over 150
		{
			public:
				const char *what() const throw();
		};

};

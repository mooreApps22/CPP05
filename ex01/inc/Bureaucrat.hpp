#pragma once
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
		// Bureaucrat Utils
		void			signForm(Form& paper);
		void			decrementGrade(void);
		void			incrementGrade(void);
		std::string		getName(void) const;
		int				getGrade(void) const;
		// Member Functions
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
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
    private:
        const std::string	_name;
		int					_grade;
};

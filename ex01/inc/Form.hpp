#pragma once
# include <iostream>
# include "Bureaucrat.hpp"

/*
*/
class Bureaucrat;

class Form
{
    public:
		//Utils
		void				beSigned(Bureaucrat& buddy, std::string reason);
		const std::string	getName(void) const;
		int					gradeRequirement(void) const;
		int					executionRequirement(void) const;
		bool				hasBeenSigned(void) const;
				
		//Special Members

        Form();
        Form(const std::string& name, const int gradeSignReq, const int gradeExecReq);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

		//Exception
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class BureaucratGradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

    private:
		// Attributes
        const std::string	_name;
		bool				_isSigned;
		const int			_gradeSignRequirement;
		const int			_gradeExecRequirement;
};

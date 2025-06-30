#pragma once
# include <iostream>
/*
*/

class Form
{
    public:
		//Utils
		const std::string	getName(void) const;
		const int			gradeRequirement(void) const;
		const int			executionRequirement(void) const;
		bool				hasBeenSigned(void) const;
				
		//Special Members
        Form();
        Form(const std::string& name);
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

    private:
		// Attributes
        const std::string	_name;
		bool				_isSigned;
		const int			_gradeSignRequirement;
		const int			_gradeExecRequirement;
};

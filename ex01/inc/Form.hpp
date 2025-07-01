#pragma once
# include <iostream>
/*
	Form::beSigned(Bureaucrat& buddy) // changes the form status to signed if buddy's grade is high enough (=<)
		throw exception if out of range 
*/

class Form
{
    public:
		//Utils
		const std::string	getName(void) const;
		const int			signGradeRequired(void) const;
		const int			execGradeRequired(void) const;
		bool				hasBeenSigned(void) const;
		void				beSigned(Bureaucrat& buddy);
				
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

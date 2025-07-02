#pragma once
# include <iostream>
# include "Bureaucrat.hpp"

/*
*/
class Bureaucrat;

class AForm
{
    public:
		// Virtual Destructor for polymorphism
        virtual ~AForm();

		// Pure Virtual (ABC)
		virtual	void	execute(Bureaucrat const& executor) const = 0;

		//To Be Overridden
		virtual void		beSigned(Bureaucrat& buddy, std::string reason);

		//Utils
		const std::string	getName(void) const;
		int					gradeRequirement(void) const;
		int					executionRequirement(void) const;
		bool				hasBeenSigned(void) const;
				
		//Special Members
        AForm(const std::string& name, const int gradeSignReq, const int gradeExecReq);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

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

	protected:
		AForm();

    private:
		// Attributes
        const std::string	_name;
		bool				_isSigned;
		const int			_gradeSignRequirement;
		const int			_gradeExecRequirement;
};

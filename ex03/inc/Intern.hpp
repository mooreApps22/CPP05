#pragma once
# include <iostream>
# include "AForm.hpp" 
# include <map> 

/*
typedef AForm* (Intern::*FormFactory)(std::string);
typedef std::map<std::string, FormFactory> InternForms;

*/

class Intern
{
	typedef AForm* (Intern::*formFactory)(std::string);
	typedef std::map<std::string, formFactory>	InternForms;
    public:
		AForm*	makeForm(std::string formName, std::string target);
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
	private:
		InternForms	_forms;
		AForm*		_scf(std::string target);
		AForm*		_rrf(std::string target);
		AForm*		_ppf(std::string target);
};

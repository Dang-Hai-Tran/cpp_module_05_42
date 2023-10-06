#ifndef INTERN_HPP
#define INTERN_HPP

#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern {
  private:
    typedef struct sFormList {
        std::string const &formName;
        AForm *(*function)(std::string const &);
    } formList;

  public:
    Intern(void);
    Intern(Intern const &other);
    ~Intern(void);
    Intern &operator=(Intern const &other);
    AForm *makeForm(std::string formName, std::string target);
    class InvalidFormName : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };
};

#endif

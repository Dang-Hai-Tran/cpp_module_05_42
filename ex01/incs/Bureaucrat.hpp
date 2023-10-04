#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;
    Bureaucrat();
    Bureaucrat(Bureaucrat &other);
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();

    const std::string getName(void);
    int getGrade(void);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };
    void increment(unsigned int addGrade);
    void decrement(unsigned int minusGrade);
    void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);

#endif

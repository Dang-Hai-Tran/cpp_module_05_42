#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "./AForm.hpp"

class AForm;

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
    Bureaucrat &operator=(Bureaucrat &other);

    const std::string getName(void) const;
    int getGrade(void) const;

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
    void signForm(AForm &form);
    void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);

#endif

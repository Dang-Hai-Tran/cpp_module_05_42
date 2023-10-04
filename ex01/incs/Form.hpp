#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

  public:
    Form(void);
    Form(Form &other);
    Form(const std::string name, bool isSigned, int signGrade, int execGrade);
    ~Form();
    std::string getName(void);
    bool getIsSigned(void);
    int getSignGrade(void);
    int getExecGrade(void);
    void beSigned(Bureaucrat &b);
    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };

    class AlreadySignedException : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif

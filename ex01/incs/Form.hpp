#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
  private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

  public:
    Form(void);
    Form(std::string name, int signGrade, int execGrade);
    const std::string getName();
    const bool getIsSigned();
    const int getSignGrade();
    const int getExecGrade();
    void beSigned(const Bureaucrat &b);
    class GradeTooHighException;
    class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif

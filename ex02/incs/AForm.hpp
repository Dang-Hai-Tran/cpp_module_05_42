#ifndef FORM_HPP
#define FORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

  public:
    AForm(void);
    AForm(AForm const &other);
    AForm(const std::string name, bool isSigned, int signGrade, int execGrade);
    virtual ~AForm();
    AForm &operator=(AForm &other);

    std::string getName(void) const;
    bool getIsSigned(void);
    int getSignGrade(void);
    int getExecGrade(void);
    void beSigned(Bureaucrat &b);
    void execute(Bureaucrat const &executor) const;
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

    class NotSignedException : public std::exception {
      public:
        virtual const char *what(void) const throw();
    };

  protected:
    virtual void beExecuted(void) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm &form);

#endif

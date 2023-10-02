#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

  public:
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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);

#endif

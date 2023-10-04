#include "../incs/Form.hpp"

Form::Form()
    : _name("Base Form"), _isSigned(false), _signGrade(0), _execGrade(0) {
    std::cout << "Form default constructor called" << std::endl;
};

Form::Form(Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, bool isSigned, int signGrade, int execGrade)
    : _name(name), _isSigned(isSigned), _signGrade(signGrade),
      _execGrade(execGrade) {
    std::cout << "Constructor with name = " << name
              << "; isSigned = " << isSigned << "; signGrade = " << signGrade
              << "; execGrade = " << execGrade << " called" << std::endl;
    if (signGrade > Bureaucrat::LOWEST_GRADE ||
        execGrade > Bureaucrat::LOWEST_GRADE)
        throw(Form::GradeTooLowException());
    if (signGrade < Bureaucrat::HIGHEST_GRADE ||
        execGrade < Bureaucrat::HIGHEST_GRADE)
        throw(Form::GradeTooHighException());
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

std::string Form::getName(void) { return this->_name; }

bool Form::getIsSigned(void) { return this->_isSigned; }

int Form::getSignGrade(void) { return this->_signGrade; }

int Form::getExecGrade(void) { return this->_execGrade; }

void Form::beSigned(Bureaucrat &b) {
    if (this->_isSigned == true)
        throw(Form::AlreadySignedException());
    if (b.getGrade() > this->_signGrade)
        throw(Form::GradeTooLowException());
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
    return "Grade too high for form";
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "Grade too low for form";
}

const char *Form::AlreadySignedException::what(void) const throw() {
    return "Form is already signed";
}

std::ostream &operator<<(std::ostream &os, Form &form) {
    os << form.getName() << ", form isSigned " << form.getIsSigned()
       << ", form signGrade " << form.getSignGrade() << ", form execGrade "
       << form.getExecGrade();
    return os;
}

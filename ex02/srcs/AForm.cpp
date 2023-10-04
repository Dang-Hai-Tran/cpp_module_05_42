#include "../incs/AForm.hpp"

AForm::AForm()
    : _name("Base AForm"), _isSigned(false), _signGrade(0), _execGrade(0) {
    std::cout << "AForm default constructor called" << std::endl;
};

AForm::AForm(AForm const &other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int signGrade, int execGrade)
    : _name(name), _isSigned(isSigned), _signGrade(signGrade),
      _execGrade(execGrade) {
    std::cout << "Constructor with name = " << name
              << "; isSigned = " << isSigned << "; signGrade = " << signGrade
              << "; execGrade = " << execGrade << " called" << std::endl;
    if (signGrade > Bureaucrat::LOWEST_GRADE ||
        execGrade > Bureaucrat::LOWEST_GRADE)
        throw(AForm::GradeTooLowException());
    if (signGrade < Bureaucrat::HIGHEST_GRADE ||
        execGrade < Bureaucrat::HIGHEST_GRADE)
        throw(AForm::GradeTooHighException());
}

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

AForm &AForm::operator=(AForm &other) {
    std::cout << "Form assignment operator overload called." << std::endl;
    this->_isSigned = other._isSigned;
    return (*this);
}

std::string AForm::getName(void) const { return this->_name; }

bool AForm::getIsSigned(void) { return this->_isSigned; }

int AForm::getSignGrade(void) { return this->_signGrade; }

int AForm::getExecGrade(void) { return this->_execGrade; }

void AForm::beSigned(Bureaucrat &b) {
    if (this->_isSigned == true)
        throw(AForm::AlreadySignedException());
    if (b.getGrade() > this->_signGrade)
        throw(AForm::GradeTooLowException());
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &b) const {
    if (this->_isSigned == false)
        throw(AForm::NotSignedException());
    if (b.getGrade() > this->_execGrade)
        throw(AForm::GradeTooLowException());
    this->beExecuted();
}

const char *AForm::GradeTooHighException::what(void) const throw() {
    return "Grade too high for form";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
    return "Grade too low for form";
}

const char *AForm::AlreadySignedException::what(void) const throw() {
    return "Form is already signed";
}

const char *AForm::NotSignedException::what(void) const throw() {
    return ("Form has not been signed.");
}

std::ostream &operator<<(std::ostream &os, AForm &form) {
    os << form.getName() << ", form isSigned " << form.getIsSigned()
       << ", form signGrade " << form.getSignGrade() << ", form execGrade "
       << form.getExecGrade();
    return os;
}

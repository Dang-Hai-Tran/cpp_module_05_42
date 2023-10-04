#include "../incs/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", false,
            PresidentialPardonForm::gradeToSign,
            PresidentialPardonForm::gradeToExecute),
      _target("Unknown") {
    std::cout << "PresidentialPardonForm default constructor called."
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("Presidential Pardon Form", false,
            PresidentialPardonForm::gradeToSign,
            PresidentialPardonForm::gradeToExecute),
      _target(target) {
    std::cout << "PresidentialPardonForm constructor with target = " << target
              << " called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    this->_target = other._target;
    return *this;
}

std::string const &PresidentialPardonForm::getTarget(void) const {
    return this->_target;
}

void PresidentialPardonForm::beExecuted(void) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

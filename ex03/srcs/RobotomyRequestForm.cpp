#include "../incs/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy Request Form", false, RobotomyRequestForm::gradeToSign,
            RobotomyRequestForm::gradeToExecute),
      _target("Unknown") {
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("Robotomy Request Form", false, RobotomyRequestForm::gradeToSign,
            RobotomyRequestForm::gradeToExecute),
      _target(target) {
    std::cout << "RobotomyRequestForm constructor with target = " << target
              << " called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    this->_target = other._target;
    return (*this);
}

std::string const &RobotomyRequestForm::getTarget(void) const {
    return this->_target;
}

void RobotomyRequestForm::beExecuted(void) const {
    std::cout << "...Drilling noises... bip bip bip..." << std::endl;
    if (std::rand() % 2)
        std::cout << this->_target << " successfully robotomized." << std::endl;
    else
        std::cout << this->_target << " unsuccessfully robotomized."
                  << std::endl;
}

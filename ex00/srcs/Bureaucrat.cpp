#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Base Bureaucrat"), _grade(0) {
    std::cout << "Bureaucrat default constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat constructor name = " << name
              << "; grade = " << grade << " called." << std::endl;
    if (grade > Bureaucrat::LOWEST_GRADE)
        throw(Bureaucrat::GradeTooLowException());
    else if (grade < Bureaucrat::HIGHEST_GRADE)
        throw(Bureaucrat::GradeTooHighException());
    else {
        this->_grade = grade;
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other) {
    std::cout << "Bureaucrat assignment operator overload called." << std::endl;
    this->_grade = other._grade;
    return (*this);
}

const std::string Bureaucrat::getName(void) { return this->_name; };

int Bureaucrat::getGrade(void) { return this->_grade; }

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Bureaucrat grade too high (<1)";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Bureaucrat grade too low (>150)";
}

void Bureaucrat::increment(unsigned int addGrade) {
    if ((int)(this->_grade - addGrade) < Bureaucrat::HIGHEST_GRADE)
        throw(Bureaucrat::GradeTooHighException());
    else
        this->_grade -= addGrade;
}

void Bureaucrat::decrement(unsigned int minusGrade) {
    if ((int)(this->_grade + minusGrade) > Bureaucrat::LOWEST_GRADE)
        throw(Bureaucrat::GradeTooLowException());
    else
        this->_grade += minusGrade;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade "
       << bureaucrat.getGrade();
    return os;
}

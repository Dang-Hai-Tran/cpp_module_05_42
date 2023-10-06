#include "../incs/Intern.hpp"

Intern::Intern(void) {
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &other) {
    std::cout << "Intern copy constructor called." << std::endl;
    *this = other;
}

Intern::~Intern(void) {
    std::cout << "Intern destructor called." << std::endl;
}

Intern &Intern::operator=(Intern const &other) {
    std::cout << "Intern assignment operator overload called." << std::endl;
    (void)other;
    return (*this);
}

static AForm *createPresidentialPardonForm(std::string const &target) {
    return (new PresidentialPardonForm(target));
}

static AForm *createRobotomyRequestForm(std::string const &target) {
    return (new RobotomyRequestForm(target));
}

static AForm *createShrubberyCreationForm(std::string const &target) {
    return (new ShrubberyCreationForm(target));
}

const char *Intern::InvalidFormName::what(void) const throw() {
    return ("Invalid form name");
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    AForm *formToCreate = NULL;
    static formList const form[3] = {
        {"shrubbery creation", createShrubberyCreationForm},
        {"robotomy request", createRobotomyRequestForm},
        {"presidential pardon", createPresidentialPardonForm}};
    for (int i = 0; i < 3; i++) {
        if (form[i].formName == formName) {
            formToCreate = form[i].function(target);
            std::cout << "Interm created " << *formToCreate << std::endl;
            return formToCreate;
        }
    }
    std::cout << "Intern couldn't create form named " << formName << std::endl;
    throw Intern::InvalidFormName();
}

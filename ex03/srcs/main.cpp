#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/Intern.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"

void testInternCreateForm(std::string formName, std::string target) {
    std::cout << "****** Test Intern Create Form " << formName
              << " with target " << target << " ******" << std::endl;
    Intern emily = Intern();
    Bureaucrat boss("Harry", 10);
    AForm *form;
    try {
        form = emily.makeForm(formName, target);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main(void) {
    testInternCreateForm("shrubbery creation", "James");
    testInternCreateForm("robotomy request", "Robert");
    testInternCreateForm("presidential pardon", "John");
    testInternCreateForm("bad form name", "Michael");
}

#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat oneEmployee("One", 142);
    Bureaucrat twoEmployee("Two", 75);
    Bureaucrat threeEmployee("Three", 3);
    std::cout << "****** Three bureaucrats created : ******" << std::endl;
    std::cout << oneEmployee << std::endl;
    std::cout << twoEmployee << std::endl;
    std::cout << threeEmployee << std::endl;
    ShrubberyCreationForm shrubForm("Manager");
    RobotomyRequestForm robotForm("CEO");
    PresidentialPardonForm presidentialForm(threeEmployee.getName());
    std::cout << "****** Three forms created: ******" << std::endl;
    std::cout << shrubForm << std::endl;
    std::cout << robotForm << std::endl;
    std::cout << presidentialForm << std::endl;
    std::cout << "****** Signing and executing Shrubbery Form: ******"
              << std::endl;
    oneEmployee.signForm(shrubForm);
    oneEmployee.executeForm(shrubForm);
    oneEmployee.increment(7);
    oneEmployee.executeForm(shrubForm);
    std::cout << "****** Signing and executing Robotomy Form: ******"
              << std::endl;
    twoEmployee.signForm(robotForm);
    twoEmployee.executeForm(robotForm);
    std::cout << "****** Signing and executing Presidential Form: ******"
              << std::endl;
    threeEmployee.signForm(presidentialForm);
    threeEmployee.executeForm(presidentialForm);
}

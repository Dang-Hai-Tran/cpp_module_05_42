#include "../incs/Bureaucrat.hpp"

void createBureaucrat(const std::string name, int grade) {
    try {
        Bureaucrat employee(name, grade);
        std::cout << employee << " create successfully." << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void incrementBureaucrat(Bureaucrat &employee, unsigned int addGrade) {
    try {
        employee.increment(addGrade);
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void decrementBureaucrat(Bureaucrat &employee, unsigned int minusGrade) {
    try {
        employee.decrement(minusGrade);
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main(void) {
    std::cout << "****** TEST CREATE BUREAUCRAT ******" << std::endl;
    createBureaucrat("One", -4);
    createBureaucrat("Two", 5);
    createBureaucrat("Three", 160);
    std::cout << "****** TEST INCREMENT ******" << std::endl;
    Bureaucrat one("One", 10);
    incrementBureaucrat(one, 5);
    std::cout << one << std::endl;
    incrementBureaucrat(one, 10);
    std::cout << one << std::endl;
    std::cout << "****** TEST DECREMENT ******" << std::endl;
    Bureaucrat two("Two", 100);
    decrementBureaucrat(two, 30);
    std::cout << two << std::endl;
    decrementBureaucrat(two, 40);
    std::cout << two << std::endl;
}

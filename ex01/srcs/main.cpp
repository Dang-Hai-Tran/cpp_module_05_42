#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

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

void createForm(const std::string name, bool isSigned, int signGrade,
                int execGrade) {
    try {
        Form form(name, isSigned, signGrade, execGrade);
        std::cout << form << " create successfully." << std::endl;
    } catch (Form::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void formBeSigned(Form &form, Bureaucrat &person) {
    try {
        form.beSigned(person);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main(void) {
    {
        std::cout << "****** TEST CREATE FORM ******" << std::endl;
        createForm("Form one", true, 70, 100);
        createForm("Form tow", false, -5, 100);
        createForm("Form three", false, 180, 100);
        createForm("Form four", true, 60, -20);
        createForm("Form five", true, 60, 200);
    }
    {
        std::cout << "******* TEST BESIGNED FORM FUNCTION ******" << std::endl;
        Bureaucrat personOne("PersonOne", 20);
        Bureaucrat personTwo("PersonTwo", 120);
        Form formOne("FormOne", false, 100, 100);
        Form formTwo("FormTwo", false, 100, 100);
        // isSigned of formOne change from false to true
        formBeSigned(formOne, personOne);
        // raise an exception AlreadySigned
        formBeSigned(formOne, personOne);
        // isSigned of formTwo not change
        formBeSigned(formTwo, personTwo);
    }
    {
        std::cout << "****** TEST SIGNED BUREAUCRAT FUNCTION ******"
                  << std::endl;
        Bureaucrat wkOne("WorkerOne", 50);
        Form fOne("FormOne", false, 70, 70);
        Form fTwo("FormTwo", false, 30, 30);
        wkOne.signForm(fOne);
        wkOne.signForm(fOne);
        wkOne.signForm(fTwo);
    }
}

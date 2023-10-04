#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "./AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    std::string _target;

  public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm(std::string const &target);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    std::string const &getTarget(void) const;
    void beExecuted(void) const;
    static int const gradeToSign = 72;
    static int const gradeToExecute = 45;
};

#endif

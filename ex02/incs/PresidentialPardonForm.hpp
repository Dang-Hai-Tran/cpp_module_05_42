#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string _target;

  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm(std::string const &target);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    std::string const &getTarget(void) const;
    void beExecuted(void) const;
    static int const gradeToSign = 25;
    static int const gradeToExecute = 5;
};

#endif

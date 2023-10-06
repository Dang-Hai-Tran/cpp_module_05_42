#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
    static std::string const _shrubbery;
    static std::string const _shrubberyAlt;

  public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm(std::string const &target);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    std::string const &getTarget(void) const;
    void beExecuted(void) const;
    static int const gradeToSign = 145;
    static int const gradeToExecute = 137;
};

#endif

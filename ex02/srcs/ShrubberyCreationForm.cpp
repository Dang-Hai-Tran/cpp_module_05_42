#include "../incs/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation Form", false,
            ShrubberyCreationForm::gradeToSign,
            ShrubberyCreationForm::gradeToExecute),
      _target("Unknown") {
    std::cout << "ShrubberyCreationForm default constructor called."
              << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("Shrubbery Creation Form", false,
            ShrubberyCreationForm::gradeToSign,
            ShrubberyCreationForm::gradeToExecute),
      _target(target) {
    std::cout << "ShrubberyCreationForm constructor with target = " << target
              << " called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    this->_target = other._target;
    return (*this);
}

std::string const &ShrubberyCreationForm::getTarget(void) const {
    return this->_target;
}

void ShrubberyCreationForm::beExecuted(void) const {
    std::ofstream ofs;
    ofs.open((this->_target + "_shrubbery").c_str(),
             std::ofstream::out | std::ofstream::app);
    if (ofs.is_open()) {
        if (std::rand() % 2)
            ofs << ShrubberyCreationForm::_shrubbery;
        else
            ofs << ShrubberyCreationForm::_shrubberyAlt;
        std::cout << "A shrubbery has been planted at " << _target
                  << "_shrubbery file." << std::endl;
        ofs.close();
    }
}
std::string const ShrubberyCreationForm::_shrubbery =
    "\n"
    "                %%%,%%%%%%%\n"
    "                 ,'%% \\\\-*%%%%%%%\n"
    "           ;%%%%%*%   _%%%%\"\n"
    "            ,%%%       \\(_.*%%%%.\n"
    "            % *%%, ,%%%%*(    '\n"
    "          %^     ,*%%% )\\|,%%*%,_\n"
    "               *%    \\/ #).-\"*%%*\n"
    "                   _.) ,/ *%,\n"
    "           _________/)#(_____________\n\n";

std::string const ShrubberyCreationForm::_shrubberyAlt =
    "\n"
    "           \\/ |    |/\n"
    "        \\/ / \\||/  /_/___/_\n"
    "         \\/   |/ \\/\n"
    "    _\\__\\_\\   |  /_____/_\n"
    "           \\  | /          /\n"
    "  __ _-----`  |{,-----------~\n"
    "            \\ }{\n"
    "             }{{\n"
    "             }}{\n"
    "             {{}\n"
    "       , -=-~{ .-^- _\n"
    "             `}\n"
    "              {\n\n";

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this == &other)
    return *this;
  AForm::operator=(other);
  _target = other._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(NULL));
    seeded = true;
  }

  std::cout << "* drilling noises *" << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << _target << " has been robotomized successfully." << std::endl;
  else
    std::cout << "Robotomy of " << _target << " failed." << std::endl;
}

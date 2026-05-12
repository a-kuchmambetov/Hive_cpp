#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
  Intern intern;
  Bureaucrat alice("Alice", 1);

  AForm* shrub = intern.makeForm("shrubbery creation", "home");
  AForm* robot = intern.makeForm("robotomy request", "Bender");
  AForm* pardon = intern.makeForm("presidential pardon", "Arthur");
  AForm* unknown = intern.makeForm("unknown form", "Nobody");

  if (shrub) {
    alice.signForm(*shrub);
    alice.executeForm(*shrub);
    delete shrub;
  }
  if (robot) {
    alice.signForm(*robot);
    alice.executeForm(*robot);
    delete robot;
  }
  if (pardon) {
    alice.signForm(*pardon);
    alice.executeForm(*pardon);
    delete pardon;
  }
  if (!unknown) {
    std::cout << "Unknown form correctly returned NULL" << std::endl;
  }

  return 0;
}

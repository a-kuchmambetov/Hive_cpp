#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    alice.signForm(shrub);
    alice.signForm(robot);
    alice.signForm(pardon);

    alice.executeForm(shrub);
    alice.executeForm(robot);
    alice.executeForm(pardon);

    bob.executeForm(shrub);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat alice("Alice", 1);
    ShrubberyCreationForm shrub("garden");
    alice.executeForm(shrub);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}

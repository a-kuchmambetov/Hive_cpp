#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat b1("Alice", 1);
    std::cout << b1 << std::endl;

    Bureaucrat b2("Bob", 150);
    std::cout << b2 << std::endl;

    b2.incrementGrade();
    std::cout << b2 << std::endl;

    b1.decrementGrade();
    std::cout << b1 << std::endl;

    Bureaucrat b3("Charlie", 0);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat b4("Dave", 151);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat b5("Eve", 1);
    b5.incrementGrade();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat b6("Frank", 150);
    b6.decrementGrade();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}

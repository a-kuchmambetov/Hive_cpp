#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);
    Form f1("TaxForm", 1, 1);
    Form f2("SimpleForm", 150, 150);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    b1.signForm(f1);
    b2.signForm(f1);
    b2.signForm(f2);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}

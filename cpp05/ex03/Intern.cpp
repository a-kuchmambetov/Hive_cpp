#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
  (void)other;
}

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

typedef AForm* (Intern::*FormFactory)(const std::string&) const;

struct FormEntry {
  const char* name;
  FormFactory factory;
};

AForm* Intern::makeShrubbery(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
  static const FormEntry entries[] = {
    { "shrubbery creation", &Intern::makeShrubbery },
    { "robotomy request", &Intern::makeRobotomy },
    { "presidential pardon", &Intern::makePardon }
  };
  static const int count = sizeof(entries) / sizeof(entries[0]);

  for (int i = 0; i < count; ++i) {
    if (formName == entries[i].name) {
      AForm* form = (this->*entries[i].factory)(target);
      std::cout << "Intern creates " << formName << std::endl;
      return form;
    }
  }

  std::cerr << "Error: Intern doesn't know how to create \"" << formName << "\"" << std::endl;
  return 0;
}

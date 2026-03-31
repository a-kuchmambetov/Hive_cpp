#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
  std::cout << "WrongAnimal Type constructor called\n";
}

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal Default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy constructor called\n";
  *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy assignment operator called\n";

  if (this == &other)
    return *this;

  _type = other._type;

  return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal Destructor called\n"; }

std::string const &WrongAnimal::getType() const { return _type; }

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal cannot make a sound\n";
}

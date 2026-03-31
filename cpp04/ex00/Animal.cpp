#include "Animal.hpp"
#include <iostream>

Animal::Animal(const std::string &type) : _type(type) {
  std::cout << "Animal Type constructor called\n";
}

Animal::Animal() : _type("Animal") {
  std::cout << "Animal Default constructor called\n";
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal Copy constructor called\n";
  *this = other;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal Copy assignment operator called\n";

  if (this == &other)
    return *this;

  _type = other._type;

  return *this;
}

Animal::~Animal() { std::cout << "Animal Destructor called\n"; }

std::string const &Animal::getType() const { return _type; }

void Animal::makeSound() const { std::cout << "Animal cannot make a sound\n"; }

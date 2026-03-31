#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog Default constructor called\n";

  _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain()) {
  std::cout << "Dog Copy constructor called\n";
  *this = other;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Copy assignment operator called\n";

  if (this == &other)
    return *this;

  Animal::operator=(other);
  *_brain = *other._brain;

  return *this;
}

Dog::~Dog() {
  std::cout << "Dog Destructor called\n";
  delete _brain;
}

void Dog::makeSound() const { std::cout << "Dog - Woof-ruff\n"; }

void Dog::setIdea(int index, const std::string &idea) {
  _brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const {
  return _brain->getIdea(index);
}

const Brain *Dog::getBrain() const { return _brain; }

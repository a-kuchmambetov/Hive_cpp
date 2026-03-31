#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat Default constructor called\n";

  _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain()) {
  std::cout << "Cat Copy constructor called\n";
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Copy assignment operator called\n";

  if (this == &other)
    return *this;

  Animal::operator=(other);
  *_brain = *other._brain;

  return *this;
}

Cat::~Cat() {
  std::cout << "Cat Destructor called\n";
  delete _brain;
}

void Cat::makeSound() const { std::cout << "Cat - meow-meow\n"; }

void Cat::setIdea(int index, const std::string &idea) {
  _brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(int index) const {
  return _brain->getIdea(index);
}

const Brain *Cat::getBrain() const { return _brain; }

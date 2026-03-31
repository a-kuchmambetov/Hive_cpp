#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain Default constructor called\n"; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain Copy constructor called\n";
  *this = other;
}

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain Copy assignment operator called\n";

  if (this == &other)
    return *this;

  for (int i = 0; i < 100; i++)
    ideas[i] = other.ideas[i];

  return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
  if (index >= 0 && index < 100)
    ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const {
  static const std::string empty = "";

  if (index >= 0 && index < 100)
    return ideas[index];
  return empty;
}

Brain::~Brain() { std::cout << "Brain Destructor called\n"; }

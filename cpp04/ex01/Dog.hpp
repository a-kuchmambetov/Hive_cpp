#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *_brain;

public:
  Dog();
  Dog(const Dog &other);
  ~Dog();

  Dog &operator=(const Dog &other);

  void makeSound() const;
  void setIdea(int index, const std::string &idea);
  const std::string &getIdea(int index) const;
  const Brain *getBrain() const;
};

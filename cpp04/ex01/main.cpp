#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

static void printDogCopyTest() {
  Dog original;
  original.setIdea(0, "bone");

  Dog copied(original);
  copied.setIdea(0, "ball");

  std::cout << "\nDog copy constructor test\n";
  std::cout << "original brain: " << original.getBrain() << "\n";
  std::cout << "copied brain:   " << copied.getBrain() << "\n";
  std::cout << "original idea:  " << original.getIdea(0) << "\n";
  std::cout << "copied idea:    " << copied.getIdea(0) << "\n\n";
}

static void printCatAssignmentTest() {
  Cat original;
  original.setIdea(0, "sleep");

  Cat assigned;
  assigned = original;
  assigned.setIdea(0, "eat");

  std::cout << "\nCat assignment operator test\n";
  std::cout << "original brain: " << original.getBrain() << "\n";
  std::cout << "assigned brain: " << assigned.getBrain() << "\n";
  std::cout << "original idea:  " << original.getIdea(0) << "\n";
  std::cout << "assigned idea:  " << assigned.getIdea(0) << "\n\n";
}

int main() {
  {
    const int SIZE = 4;
    const Animal *meta[SIZE];

    for (int i = 0; i < SIZE; i++)
      if (i < SIZE / 2)
        meta[i] = new Cat();
      else
        meta[i] = new Dog();

    for (const Animal *animal : meta)
      delete animal;

    std::cout << "\n";
  }
  printDogCopyTest();
  printCatAssignmentTest();

  return 0;
}

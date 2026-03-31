#pragma once
#include <string>

class WrongAnimal {
protected:
  std::string _type;

  WrongAnimal(const std::string &type);

public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  virtual ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &other);

  const std::string &getType() const;

  void makeSound() const;
};

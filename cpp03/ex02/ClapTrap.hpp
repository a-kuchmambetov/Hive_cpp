#pragma once
#include <string>

class ClapTrap {
protected:
  std::string _name;
  unsigned int _hP;
  unsigned int _eP;
  unsigned int _attackDamage;

  ClapTrap(const std::string &name, const unsigned int hP,
           const unsigned int eP, const unsigned int attackDamage);

public:
  ClapTrap();
  ClapTrap(const std::string name);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &other);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

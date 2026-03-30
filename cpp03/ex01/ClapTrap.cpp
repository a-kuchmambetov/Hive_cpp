#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name, const unsigned int hP,
                   const unsigned int eP, const unsigned int attackDamage)
    : _name(name), _hP(hP), _eP(eP), _attackDamage(attackDamage) {
  std::cout << "ClapTrap all fields protected constructor called\n";
}

ClapTrap::ClapTrap() : _name(""), _hP(10), _eP(10), _attackDamage(0) {
  std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string name)
    : _name(name), _hP(10), _eP(10), _attackDamage(0) {
  std::cout << "ClapTrap Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "ClapTrap Copy constructor called\n";
  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap Copy assignment operator called\n";

  if (this == &other)
    return *this;

  _name = other._name;
  _hP = other._hP;
  _eP = other._eP;
  _attackDamage = other._attackDamage;

  return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called\n"; }

void ClapTrap::attack(const std::string &target) {
  if (_eP <= 0) {
    std::cout << "ClapTrap " << _name << " has not enough energy to attack!\n";
    return;
  }

  _eP--;

  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hP < amount) {
    _hP = 0;
    return;
  }

  _hP -= amount;

  std::cout << _name << " took " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_eP <= 0) {
    std::cout << _name << " has not enough energy to be repaired!\n";
    return;
  }

  _eP--;
  _hP += amount;

  std::cout << _name << " been repaired by " << amount
            << " points of health!\n";
}

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20) {
  std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "ScavTrap Name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap Copy assignment operator called\n";

  if (this != &other)
    ClapTrap::operator=(other);

  return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called\n"; }

void ScavTrap::attack(const std::string &target) {
  if (_eP <= 0) {
    std::cout << "ScavTrap " << _name << " has not enough energy to attack!\n";
    return;
  }

  _eP--;

  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}

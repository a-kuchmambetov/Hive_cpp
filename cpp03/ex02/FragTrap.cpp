#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30) {
  std::cout << "FragTrap Default constructor called\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "FragTrap Name constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap Copy assignment operator called\n";

  if (this != &other)
    ClapTrap::operator=(other);

  return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called\n"; }

void FragTrap::attack(const std::string &target) {
  if (_eP <= 0) {
    std::cout << "FragTrap " << _name << " has not enough energy to attack!\n";
    return;
  }

  _eP--;

  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << " is giving high fives to all guys!\n";
}

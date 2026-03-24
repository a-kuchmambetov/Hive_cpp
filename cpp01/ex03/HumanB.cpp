#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; };

void HumanB::attack() {
  if (!_weapon) {
    std::cout << _name << " cannot attack without weapon\n";
    return;
  }
  std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}

#pragma once
#include "Weapon.hpp"
#include <string>

class HumanB {
private:
  std::string _name;
  Weapon *_weapon;

public:
  HumanB(std::string name);
  ~HumanB();

  void setWeapon(Weapon &weapon);
  void attack();
};

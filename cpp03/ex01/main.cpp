#include "ScavTrap.hpp"
#include <iostream>

int main() {
  ScavTrap a("Jully");
  ScavTrap b("Romeo");

  std::cout << "\n";

  a.attack("Romeo");
  b.takeDamage(20);
  b.beRepaired(20);

  std::cout << "\n";

  for (int i = 0; i < 50; i++)
    a.beRepaired(1);
  a.attack("Romeo");
  a.guardGate();

  std::cout << "\n";
}

#include "FragTrap.hpp"
#include <iostream>

int main() {
  FragTrap a("Jully");
  FragTrap b("Romeo");

  std::cout << "\n";

  a.attack("Romeo");
  b.takeDamage(20);
  b.beRepaired(20);

  std::cout << "\n";

  for (int i = 0; i < 100; i++)
    a.beRepaired(1);
  a.attack("Romeo");
  a.highFivesGuys();

  std::cout << "\n";
}

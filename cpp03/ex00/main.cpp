#include "ClapTrap.hpp"

int main() {
  ClapTrap a("Jully");
  ClapTrap b("Romeo");

  a.attack("Romeo");
  b.takeDamage(10);
  b.beRepaired(10);

  for (int i = 0; i < 11; i++)
    a.beRepaired(1);
}

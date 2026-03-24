#include "Zombie.h"

int main() {
  Zombie *zombiePtr = newZombie("Singer");
  zombiePtr->announce();
  delete zombiePtr;

  randomChump("Butcher");
}

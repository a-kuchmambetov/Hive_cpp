#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombiePack = new Zombie[N];

  for (int i = 0; i < N; i++)
    zombiePack[i].setName(name);

  return zombiePack;
}

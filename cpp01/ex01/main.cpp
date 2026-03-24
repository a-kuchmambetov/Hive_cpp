#include "Zombie.h"
#include "Zombie.hpp"

int main() {
  const int N = 8;
  Zombie *zombiePtr = zombieHorde(N, "Singer");

  for (int i = 0; i < N; i++) {
    std::cout << i + 1 << ' ';
    zombiePtr[i].announce();
  }

  delete[] zombiePtr;
}

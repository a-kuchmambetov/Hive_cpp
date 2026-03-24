#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name) { _name = name; }
Zombie::~Zombie() { std::cout << _name << ": destroyed\n"; }

void Zombie::announce() { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }

#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(NULL));
    seeded = true;
  }

  int r = std::rand() % 3;
  if (r == 0)
    return new A();
  else if (r == 1)
    return new B();
  else
    return new C();
}

void identify(Base* p) {
  if (p == 0) {
    std::cout << "Unknown" << std::endl;
    return;
  }

  if (dynamic_cast<A*>(p) != 0)
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p) != 0)
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p) != 0)
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception&) {}

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception&) {}

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception&) {}

  std::cout << "Unknown" << std::endl;
}

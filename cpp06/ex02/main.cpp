#include "Identify.hpp"
#include "Base.hpp"
#include <iostream>

int main() {
  for (int i = 0; i < 10; ++i) {
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;
  }
  return 0;
}

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << Fixed(2) - Fixed(1) << std::endl;
  // 4 / 2 + 1  => 3 * 2 => 6
  std::cout << (Fixed(4) / Fixed(2.0f) + Fixed(1.0f)) * Fixed(2);
  // Crash case;
  // std::cout << a / Fixed(0);
  return 0;
}

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
  std::cout << "Default constructor called\n";
  fixed_pnum = 0;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";

  if (this == &other)
    return *this;

  fixed_pnum = other.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";
  return fixed_pnum;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  fixed_pnum = raw;
}

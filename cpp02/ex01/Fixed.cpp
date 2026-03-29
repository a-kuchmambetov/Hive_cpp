#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
  std::cout << "Default constructor called\n";
  _raw = 0;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called\n";
  _raw = value << FRACT;
}
Fixed::Fixed(const float value) {
  std::cout << "Float constructor called\n";
  _raw = roundf(value * (1 << FRACT));
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";

  if (this == &other)
    return *this;

  _raw = other.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

int Fixed::getRawBits() const { return _raw; }

void Fixed::setRawBits(int const raw) { _raw = raw; }

float Fixed::toFloat(void) const { return _raw / 256.0; }

int Fixed::toInt(void) const { return _raw / (1 << FRACT); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

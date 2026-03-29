#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(const int raw, bool) : _raw(raw) {}

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

bool Fixed::operator>(const Fixed &other) const {
  return _raw > other._raw;
}

bool Fixed::operator<(const Fixed &other) const {
  return _raw < other._raw;
}

bool Fixed::operator>=(const Fixed &other) const {
  return _raw >= other._raw;
}

bool Fixed::operator<=(const Fixed &other) const {
  return _raw <= other._raw;
}

bool Fixed::operator==(const Fixed &other) const {
  return _raw == other._raw;
}

bool Fixed::operator!=(const Fixed &other) const {
  return _raw != other._raw;
}

Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(_raw + other._raw, true);
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(_raw - other._raw, true);
}

Fixed Fixed::operator*(const Fixed &other) const {
  long product;

  product = static_cast<long>(_raw) * other._raw;
  return Fixed(static_cast<int>(product / (1 << FRACT)), true);
}

Fixed Fixed::operator/(const Fixed &other) const {
  long dividend;

  dividend = static_cast<long>(_raw) << FRACT;
  return Fixed(static_cast<int>(dividend / other._raw), true);
}

Fixed &Fixed::operator++() {
  ++_raw;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);

  ++_raw;
  return tmp;
}

Fixed &Fixed::operator--() {
  --_raw;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);

  --_raw;
  return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a < b)
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a < b)
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a > b)
    return a;
  return b;
}

int Fixed::getRawBits() const { return _raw; }

void Fixed::setRawBits(int const raw) { _raw = raw; }

float Fixed::toFloat(void) const { return _raw / 256.0; }

int Fixed::toInt(void) const { return _raw / (1 << FRACT); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

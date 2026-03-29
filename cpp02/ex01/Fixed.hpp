#include <iostream>

class Fixed {
private:
  const int FRACT = 8;
  int _raw;

public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);

  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

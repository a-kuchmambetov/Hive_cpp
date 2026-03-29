

class Fixed {
private:
  const int fract_bit = 8;
  int fixed_pnum;

public:
  Fixed();
  Fixed(const Fixed &src);

  Fixed &operator=(const Fixed &src);

  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

namespace {

enum LiteralType {
  TYPE_INVALID,
  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_PSEUDO_FLOAT,
  TYPE_PSEUDO_DOUBLE
};

bool isPseudoFloat(const std::string& s) {
  return s == "nanf" || s == "+inff" || s == "-inff";
}

bool isPseudoDouble(const std::string& s) {
  return s == "nan" || s == "+inf" || s == "-inf";
}

bool isCharLiteral(const std::string& s) {
  if (s.length() == 3 && s[0] == '\'' && s[2] == '\''
      && std::isprint(static_cast<unsigned char>(s[1])))
    return true;
  if (s.length() == 1 && std::isprint(static_cast<unsigned char>(s[0]))
      && !std::isdigit(static_cast<unsigned char>(s[0])))
    return true;
  return false;
}

bool isIntLiteral(const std::string& s) {
  if (s.empty())
    return false;
  size_t i = 0;
  if (s[0] == '+' || s[0] == '-')
    i++;
  if (i == s.length())
    return false;
  for (; i < s.length(); ++i) {
    if (!std::isdigit(static_cast<unsigned char>(s[i])))
      return false;
  }
  return true;
}

bool isFloatLiteral(const std::string& s) {
  if (s.empty() || s[s.length() - 1] != 'f')
    return false;
  if (s.find('.') == std::string::npos)
    return false;
  std::string sub = s.substr(0, s.length() - 1);
  char* endptr;
  std::strtod(sub.c_str(), &endptr);
  return *endptr == '\0';
}

bool isDoubleLiteral(const std::string& s) {
  if (s.empty() || s[s.length() - 1] == 'f')
    return false;
  if (s.find('.') == std::string::npos)
    return false;
  char* endptr;
  std::strtod(s.c_str(), &endptr);
  return *endptr == '\0';
}

LiteralType detectType(const std::string& s) {
  if (isPseudoFloat(s))
    return TYPE_PSEUDO_FLOAT;
  if (isPseudoDouble(s))
    return TYPE_PSEUDO_DOUBLE;
  if (isCharLiteral(s))
    return TYPE_CHAR;
  if (isFloatLiteral(s))
    return TYPE_FLOAT;
  if (isDoubleLiteral(s))
    return TYPE_DOUBLE;
  if (isIntLiteral(s))
    return TYPE_INT;
  return TYPE_INVALID;
}

bool isIntegerValue(double d) {
  double intpart;
  return std::modf(d, &intpart) == 0.0;
}

void printFloat(double d) {
  float f = static_cast<float>(d);
  if (f == std::numeric_limits<float>::infinity()
      || f == -std::numeric_limits<float>::infinity()
      || f != f) {
    std::cout << "impossible";
    return;
  }
  if (isIntegerValue(static_cast<double>(f))) {
    std::cout << f << ".0f";
  } else {
    std::cout << f << "f";
  }
}

void printDouble(double d) {
  if (d == std::numeric_limits<double>::infinity()
      || d == -std::numeric_limits<double>::infinity()
      || d != d) {
    std::cout << "impossible";
    return;
  }
  if (isIntegerValue(d)) {
    std::cout << d << ".0";
  } else {
    std::cout << d;
  }
}

} // namespace

void ScalarConverter::convert(const std::string& literal) {
  LiteralType type = detectType(literal);

  if (type == TYPE_INVALID) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  if (type == TYPE_PSEUDO_FLOAT) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal << std::endl;
    std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    return;
  }

  if (type == TYPE_PSEUDO_DOUBLE) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan")
      std::cout << "float: nanf" << std::endl;
    else if (literal == "+inf")
      std::cout << "float: +inff" << std::endl;
    else
      std::cout << "float: -inff" << std::endl;
    std::cout << "double: " << literal << std::endl;
    return;
  }

  if (type == TYPE_CHAR) {
    char c = (literal.length() == 3) ? literal[1] : literal[0];
    int i = static_cast<int>(static_cast<unsigned char>(c));
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (isIntegerValue(static_cast<double>(f))) {
      std::cout << "float: " << f << ".0f" << std::endl;
    } else {
      std::cout << "float: " << f << "f" << std::endl;
    }
    if (isIntegerValue(d)) {
      std::cout << "double: " << d << ".0" << std::endl;
    } else {
      std::cout << "double: " << d << std::endl;
    }
    return;
  }

  double value = 0.0;
  bool possible = true;

  if (type == TYPE_INT) {
    errno = 0;
    char* endptr;
    value = std::strtod(literal.c_str(), &endptr);
    if (errno == ERANGE || *endptr != '\0')
      possible = false;
  } else if (type == TYPE_FLOAT) {
    std::string sub = literal.substr(0, literal.length() - 1);
    errno = 0;
    char* endptr;
    value = std::strtod(sub.c_str(), &endptr);
    if (errno == ERANGE || *endptr != '\0')
      possible = false;
  } else if (type == TYPE_DOUBLE) {
    errno = 0;
    char* endptr;
    value = std::strtod(literal.c_str(), &endptr);
    if (errno == ERANGE || *endptr != '\0')
      possible = false;
  }

  if (!possible) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  std::cout << "char: ";
  if (value < 0 || value > 127) {
    std::cout << "impossible";
  } else {
    char c = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(c))) {
      std::cout << "'" << c << "'";
    } else {
      std::cout << "Non displayable";
    }
  }
  std::cout << std::endl;

  std::cout << "int: ";
  if (value < std::numeric_limits<int>::min()
      || value > std::numeric_limits<int>::max()) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<int>(value);
  }
  std::cout << std::endl;

  std::cout << "float: ";
  printFloat(value);
  std::cout << std::endl;

  std::cout << "double: ";
  printDouble(value);
  std::cout << std::endl;
}

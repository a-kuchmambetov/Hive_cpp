#include "truncStrCout.hpp"

std::string truncStrCout(std::string str, size_t width) {
  if (str.length() > width)
    return str.substr(0, width - 1) + ".";
  return str;
}

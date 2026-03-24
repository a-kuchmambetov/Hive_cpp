#include "Replacer.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  std::string filenameSrc;
  std::string filenameDst;
  std::string pattern;
  std::string replacement;

  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
  }

  filenameSrc = argv[1];
  pattern = argv[2];
  replacement = argv[3];

  Replacer replacer(filenameSrc, pattern, replacement);
  if (!replacer.replace())
    return 1;
  return 0;
}

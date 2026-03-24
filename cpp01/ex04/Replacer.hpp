#pragma once
#include <string>

class Replacer {
private:
  std::string _filenameSrc, _filenameDst, _pattern, _replacement;

  bool checkSourceFile();
  bool createOutputFile();
  bool isContainPattern(const std::string &src);
  std::string createReplacedStr(const std::string &src);
  // bool printLineToOutputFile(const std::string &src);

public:
  Replacer(std::string filenameSrc, std::string pattern,
           std::string replacement);
  ~Replacer();

  bool replace();
};

// check source file
// create file
// read line by line from source file
// look for same pattern
// if there is the same pattern print original string to file dst and replace
// pattern

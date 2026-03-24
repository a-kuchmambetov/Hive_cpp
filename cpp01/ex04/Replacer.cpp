#include "Replacer.hpp"

#include <fstream>
#include <iostream>

Replacer::Replacer(std::string filenameSrc, std::string pattern,
                   std::string replacement)
    : _filenameSrc(filenameSrc), _pattern(pattern), _replacement(replacement) {
  _filenameDst = _filenameSrc + ".replace";
}

Replacer::~Replacer() {}

bool Replacer::checkSourceFile() {
  std::ifstream srcFile(_filenameSrc);

  if (srcFile.is_open())
    return true;

  std::cerr << "Error: could not open source file: " << _filenameSrc
            << std::endl;
  return false;
}

bool Replacer::createOutputFile() {
  std::ofstream dstFile(_filenameDst.c_str());

  if (dstFile.is_open())
    return true;

  std::cerr << "Error: could not create output file: " << _filenameDst
            << std::endl;
  return false;
}

bool Replacer::isContainPattern(const std::string &src) {
  if (_pattern.empty())
    return false;
  return src.find(_pattern) != std::string::npos;
}

std::string Replacer::createReplacedStr(const std::string &src) {
  const std::string::size_type patternLen = _pattern.length();

  if (_pattern.empty())
    return src;

  std::string res = "";
  std::string::size_type prevPos = 0;
  std::string::size_type pos = 0;

  while (pos != std::string::npos) {
    pos = src.find(_pattern, prevPos);

    if (pos == std::string::npos) {
      res.append(src, prevPos);
      break;
    }

    res.append(src, prevPos, pos - prevPos);
    prevPos = pos + patternLen;
    res.append(_replacement);
  }

  return res;
}

bool Replacer::replace() {
  if (!checkSourceFile() || !createOutputFile())
    return false;
  std::ifstream srcFile(_filenameSrc);
  std::ofstream dstFile(_filenameDst, std::ios::app);

  std::string buffer;
  while (std::getline(srcFile, buffer)) {
    if (isContainPattern(buffer))
      dstFile << createReplacedStr(buffer) << '\n';
    else
      dstFile << buffer << '\n';
  }

  return true;
}

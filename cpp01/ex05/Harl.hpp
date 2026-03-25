#pragma once

#include <string>

class Harl {
private:
  const std::string RED = "\033[31m";
  const std::string CYAN = "\033[36m";
  const std::string YELLOW = "\033[33m";
  const std::string RESET = "\033[0m";

  void debug();
  void info();
  void warning();
  void error();

public:
  void complain(std::string level);
};

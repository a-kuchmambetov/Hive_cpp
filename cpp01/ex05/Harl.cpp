#include "Harl.hpp"

#include <iostream>

void Harl::debug() {
  std::cout
      << CYAN
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << RESET << std::endl;
}

void Harl::info() {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << YELLOW
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years, whereas you started working here just last month."
      << RESET << std::endl;
}

void Harl::error() {
  std::cout << RED
            << "This is unacceptable! I want to speak to the manager now."
            << RESET << std::endl;
}

void Harl::complain(std::string level) {
  const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                             &Harl::error};

  for (int i = 0; i < 4; i++) {
    if (level == levels[i])
      (this->*func[i])();
  }
}

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    const std::string str = argv[i];
    for (char c : str) {
      std::cout << static_cast<char>(
          std::toupper(static_cast<unsigned char>(c)));
    }
    std::cout << ' ';
  }
  std::cout << '\n';
}

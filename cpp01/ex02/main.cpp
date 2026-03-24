#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "Mem addr of string    " << &str << '\n';
  std::cout << "Mem addr in stringPTR " << stringPTR << '\n';
  std::cout << "Mem addr in stringREF " << &stringREF << '\n';
  std::cout << '\n';
  std::cout << "Value of string                   " << str << '\n';
  std::cout << "The value pointed to by stringPTR " << *stringPTR << '\n';
  std::cout << "The value pointed to by stringREF " << stringREF << '\n';

  stringREF = "Other stringREF";

  std::cout << "\nAfter content change of stringREF\n";
  std::cout << "Mem addr of string    " << &str << '\n';
  std::cout << "Mem addr in stringPTR " << stringPTR << '\n';
  std::cout << "Mem addr in stringREF " << &stringREF << '\n';
  std::cout << '\n';
  std::cout << "Value of string                   " << str << '\n';
  std::cout << "The value pointed to by stringPTR " << *stringPTR << '\n';
  std::cout << "The value pointed to by stringREF " << stringREF << '\n';
}

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret) {
  _firstName = firstName;
  _lastName = lastName;
  _nickname = nickname;
  _phoneNumber = phoneNumber;
  _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::isEmpty() {
  return _firstName.empty() && _lastName.empty() && _nickname.empty() &&
         _phoneNumber.empty() && _darkestSecret.empty();
}

void Contact::printInfo() {
  std::cout << "First name: " << _firstName << '\n';
  std::cout << "Last name: " << _lastName << '\n';
  std::cout << "Nickname: " << _nickname << '\n';
  std::cout << "Phone number: " << _phoneNumber << '\n';
  std::cout << "Darkest secret: " << _darkestSecret << '\n';
}

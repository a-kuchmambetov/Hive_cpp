#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "truncStrCout.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
  _lastContactIndex = 0;
  _contactCount = 0;
}

void PhoneBook::addContact(const Contact &contact) {
  if (_lastContactIndex == ARRAY_SIZE)
    _lastContactIndex = 0;
  _contacts[_lastContactIndex] = contact;
  if (_contactCount < ARRAY_SIZE)
    _contactCount++;
  _lastContactIndex++;
}

bool PhoneBook::isEmpty() {
  if (_contactCount == 0)
    return true;
  return false;
}

static void printTableCell(std::string src) {
  std::cout << std::setw(10) << std::right << truncStrCout(src, 10);
}

static void printTableRow(int index, Contact contact) {
  printTableCell(std::to_string(index));
  std::cout << "|";
  printTableCell(contact.getFirstName());
  std::cout << '|';
  printTableCell(contact.getLastName());
  std::cout << '|';
  printTableCell(contact.getNickname());
  std::cout << '\n';
}

void PhoneBook::printPhoneBookAsTable() {
  std::cout << std::setw(10) << std::right << "Index" << '|';
  std::cout << std::setw(10) << std::right << "First Name" << '|';
  std::cout << std::setw(10) << std::right << "Last Name" << '|';
  std::cout << std::setw(10) << std::right << "Nickname" << '\n';

  for (int i = 0; i < _contactCount; i++)
    printTableRow(i, _contacts[i]);
}

Contact PhoneBook::getContactByIndex(int index) const {
  if (index < 0 || index >= _contactCount)
    return Contact();
  return _contacts[index];
}

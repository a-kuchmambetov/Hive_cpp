#pragma once
#include "Contact.hpp"

class PhoneBook {
private:
  static const int ARRAY_SIZE = 8;
  Contact _contacts[ARRAY_SIZE];
  int _lastContactIndex;
  int _contactCount;

public:
  PhoneBook();
  void addContact(const Contact &contact);
  bool isEmpty();
  void printPhoneBookAsTable();
  Contact getContactByIndex(int index) const;
};

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <stdexcept>

#define RED "\033[31m"
#define RESET "\033[0m"

bool readline(const std::string &prompt, std::string &dest) {
  std::cout << prompt;
  if (!(std::cin >> dest))
    return false;
  return true;
}

bool readlineNonempty(const std::string &prompt, std::string &dest) {
  while (true) {
    if (!readline(prompt, dest)) {
      std::cerr << RED << "User stoped input. Closing program\n" << RESET;
      std::exit(1);
    }
    if (!dest.empty()) {
      return true;
    }
    std::cout << "Input cannot be empty\n";
  }
}

void addCommand(PhoneBook &phoneBook) {
  std::string firstName = "", lastName = "", nickname = "", phoneNumber = "",
              darkestSecret = "";

  readlineNonempty("Enter first name: ", firstName);
  readlineNonempty("Enter last name: ", lastName);
  readlineNonempty("Enter nickname: ", nickname);
  readlineNonempty("Enter phone number: ", phoneNumber);
  readlineNonempty("Enter darkest secret: ", darkestSecret);

  Contact contact =
      Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
  phoneBook.addContact(contact);

  std::cout << '\n';
}

void search(PhoneBook &phoneBook) {
  std::string indexStr;
  int indexInt;

  if (phoneBook.isEmpty()) {
    std::cout << "No entry. Add new first.\n\n";
    return;
  }

  phoneBook.printPhoneBookAsTable();

  while (1) {
    readlineNonempty("Enter index of entry to display: ", indexStr);

    try {
      indexInt = std::stoi(indexStr);
    } catch (const std::invalid_argument &e) {
      std::cout << RED
                << "Error occured while converting index to integer. Only "
                   "numbers allowed. Try again\n"
                << RESET;
      continue;
    } catch (const std::out_of_range &e) {
      std::cout << RED
                << "Error occured while converting index to integer. Number is "
                   "too small or too big. Try again\n"
                << RESET;
      continue;
    }

    Contact contact = phoneBook.getContactByIndex(indexInt);
    if (contact.isEmpty()) {
      std::cout << "Index out of range. Try again\n";
      continue;
    }

    contact.printInfo();
    break;
  }
  std::cout << '\n';
}

int main() {
  PhoneBook phoneBook;
  std::string input;

  while (1) {
    readlineNonempty("Enter one of three command:\nADD\nSEARCH\nEXIT\nFollow "
                     "case of the command.\nCommand: ",
                     input);
    std::cout << "\n";
    if (input.compare("ADD") == 0)
      addCommand(phoneBook);
    else if (input.compare("SEARCH") == 0)
      search(phoneBook);
    else if (input.compare("EXIT") == 0)
      std::exit(0);
  }
}

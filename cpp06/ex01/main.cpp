#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
  Data data;
  data.id = 42;
  data.name = "test";
  data.value = 3.14;

  std::cout << "Original pointer: " << &data << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized value: " << raw << std::endl;

  Data* ptr = Serializer::deserialize(raw);
  std::cout << "Deserialized pointer: " << ptr << std::endl;

  if (ptr == &data) {
    std::cout << "Pointers match!" << std::endl;
  } else {
    std::cout << "Pointers do not match!" << std::endl;
  }

  std::cout << "Data fields through deserialized pointer:" << std::endl;
  std::cout << "id: " << ptr->id << std::endl;
  std::cout << "name: " << ptr->name << std::endl;
  std::cout << "value: " << ptr->value << std::endl;

  return 0;
}

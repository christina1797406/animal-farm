#include <iostream>

#include "User.h"

int main() {
  std::string name;
  // Prompt the user to enter their name
  std::cout << "Please enter your name: ";
  std::getline(std::cin, name);

  int age;
  // Prompt the user to enter their age
  std::cout << "Please enter your age: ";
  std::cin >> age;

  // Clear the input buffer
  std::cin.ignore();
  // Create a user object with name and age
  User user(name, age);
  // Print user's name and age
  std::cout << "User's name: " << user.getName() << std::endl;
  std::cout << "User's age: " << user.getAge() << std::endl;

  return 0;
}
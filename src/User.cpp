#include "../include/User.h"

// Default constructor
User::User() : age(0) {}
// Constructor implementation
User::User(std::string name, int age) : name(name), age(age) {}

// Setter method
void User::setName(std::string name) { this->name = name; }
void User::setAge(int age) { this->age = age; }

// Getter method
std::string User::getName() const { return name; }
int User::getAge() const { return age; }
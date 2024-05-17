// Shovel.cpp
#include "Shovel.h"

#include <iostream>

Shovel::Shovel() : durability(4) {}

void Shovel::repair() {
  // Repair the shovel by resetting its durability
  durability = 4;
}
int Shovel::getDurability() const { return durability; }
void Shovel::Use() {
  if (durability == 0) {
    std::cout << "Shovel is not durable. Please repair it before using."
              << std::endl;
    // Here you can prompt the user to repair the shovel if needed
  } else {
    std::cout << "Shovel is durable. You can use the shovel." << std::endl;
    durability--;  // Decrement durability after each use
  }
}

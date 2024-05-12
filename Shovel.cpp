// Shovel.cpp
#include "Shovel.h"

#include <iostream>

Shovel::Shovel() : durability(4) {}

Shovel::Shovel(int durability) : durability(durability) {}

void Shovel::repair() {
  // Repair the shovel by resetting its durability
  durability = 4;
}

void Shovel::Use() {
  if (durability > 0) {
    // Perform the action using the shovel
    std::cout << "Using the shovel..." << std::endl;
    durability--;  // Example decrementing the durability
  } else {
    std::cout << "Shovel is broken. Please repair it before using."
              << std::endl;
  }
}

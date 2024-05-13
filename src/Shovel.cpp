// Shovel.cpp
#include "../include/Shovel.h"

#include <iostream>

Shovel::Shovel() : durability(0) {}

Shovel::Shovel(int durability) : durability(durability) {}

void Shovel::repair() {
  // Repair the shovel by resetting its durability
  durability = 4;
}

void Shovel::Use() {
  if (durability == 0) {
    std::cout << "Shovel is not durable. Please repair it before using."
              << std::endl;
    char choice;
    std::cout << "Do you want to repair the shovel? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
      repair();
      std::cout << "Shovel repaired. You can use it now." << std::endl;
    } else {
      std::cout << "You chose not to repair the shovel." << std::endl;
    }
  } else if (durability > 0 && durability <= 4) {
    std::cout << "Shovel is durable. You can use the shovel." << std::endl;
  } else {
    std::cout
        << "Invalid durability input. Please enter a value between 0 and 4."
        << std::endl;
  }
}

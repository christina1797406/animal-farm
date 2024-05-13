// WaterCan.cpp
#include "include/WaterCan.h"

#include <iostream>

WaterCan::WaterCan() : waterLevel(0.0) {}

WaterCan::WaterCan(double waterLevel) : waterLevel(waterLevel) {}

void WaterCan::fillWater(double amount) {
  // Fill the water can with the specified amount of water
  waterLevel += amount;
}

void WaterCan::Use() {
  // Check if the water can is empty
  if (waterLevel <= 0.0) {
    std::cout << "Water can is empty. Please fill it before using."
              << std::endl;
    fillWater(6.0);  // Fill the water can to its max capacity
    return;
  }

  // Check if the water level is less than or equal to 2 liters
  if (waterLevel <= 2.0) {
    char choice;
    std::cout << "Water can is low. Do you want to fill it to full capacity? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
      fillWater(6.0 - waterLevel);
      std::cout << "Water can is filled. You can use it now."
                << std::endl;
      return;
    } else {
      std::cout << "You can use the water can, but it will run out soon."
                << std::endl;
      return;
    }
  }

  // Check if the water level is at max capacity
  if (waterLevel == 6.0) {
    std::cout << "Water can is at max capacity. You can use it."
              << std::endl;
    return;
  }

  // Check if the water level is greater than 2 and less than 6 liters
  if (waterLevel > 2.0 && waterLevel < 6.0) {
    std::cout << "Water can is filled up to " << waterLevel
              << " liters. You can use it now." << std::endl;
    return;
  }
}

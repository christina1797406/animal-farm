// WaterCan.cpp
#include "WaterCan.h"

#include <iostream>

WaterCan::WaterCan() : waterLevel(0.0) {}

WaterCan::WaterCan(double waterLevel) : waterLevel(waterLevel) {}

void WaterCan::fillWater(double amount) {
  // Fill the water can with the specified amount of water
  waterLevel += amount;
}

void WaterCan::Use() {
  if (waterLevel > 0.0) {
    // Perform the action using the water can
    std::cout << "Using the water can..." << std::endl;
    waterLevel -= 0.5;  // Example decrementing the water level
  } else {
    std::cout << "Water can is empty. Please fill it before using."
              << std::endl;
  }
}

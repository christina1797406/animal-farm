#include <iostream>

#include "../include/WaterCan.h"

int main() {
  // Create an instance of WaterCan
  WaterCan waterCan;

  // Prompt the user to input the water level
  double waterLevel;
  std::cout << "Enter the water level of the can in liters: ";
  std::cin >> waterLevel;

  // Set the initial water level
  waterCan.fillWater(waterLevel);
  // Use the water can
  waterCan.Use();

  return 0;
}

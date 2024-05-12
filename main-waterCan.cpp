#include <iostream>

#include "WaterCan.h"

int main() {
  // Create instances of WaterCan
  WaterCan waterCan;
  // Use the equipment
  waterCan.fillWater(5.0);  // Fill the water can with 5 units of water

  // Use the water can
  waterCan.Use();

  return 0;
}
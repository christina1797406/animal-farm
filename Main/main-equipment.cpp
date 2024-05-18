// main.cpp
#include <iostream>

#include "../Include/Shovel.h"
#include "../Include/WaterCan.h"

int main() {
  // Create instances of WaterCan and Shovel
  WaterCan waterCan;
  Shovel shovel;

  // Set the number of equipment for each instance
  waterCan.set_no_of_equipment(1);
  shovel.set_no_of_equipment(1);

  // Display the number of equipment
  std::cout << "Number of Water Cans: " << waterCan.get_no_of_equipment()
            << std::endl;
  std::cout << "Number of Shovels: " << shovel.get_no_of_equipment()
            << std::endl;

  // Use the equipment (virtual function) for each instance
  waterCan.Use();  // This will call the overridden function in WaterCan
  shovel.Use();    // This will call the overridden function in Shovel

  return 0;
}

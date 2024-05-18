#include <iostream>

#include "../Include/Crop.h"

int main() {
  // Creates a crop object
  Crop crop("Oat", 5, 10, 5.5);

  // Print crop's details
  std::cout << "Crop name: " << crop.getName() << std::endl;
  std::cout << "Growth rate: " << crop.get_growthRate() << std::endl;
  std::cout << "Crop name: " << crop.get_waterNeeded() << std::endl;
  std::cout << "Harvest yield: " << crop.get_harvestYield() << std::endl;
  std::cout << "Is it harvested: " << (crop.get_isHarvested() ? "Yes" : "No")
            << std::endl;

  return 0;
}
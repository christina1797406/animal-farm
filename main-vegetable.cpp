#include <iostream>

#include "Vegetable.h"

int main() {
  std::string type;
  std::cout << "Choose vegetable type (potato or pumpkin): ";
  std::cin >> type;

  // Validate user input
  while (type != "potato" && type != "pumpkin") {
    std::cout << "Invalid input. Please choose potato or pumpkin: ";
    std::cin >> type;
  }

  int daysToHarvest;
  std::cout << "Enter days to harvest: ";
  std::cin >> daysToHarvest;

  // Create a Vegetable object based on user input
  Vegetable veg("", 0, 0, 0.0, type, daysToHarvest);

  // Display vegetable details
  std::cout << "\nVegetable Details:" << std::endl;
  std::cout << "Type: " << veg.getType() << std::endl;
  std::cout << "Days to Harvest: " << veg.getDaysToHarvest() << std::endl;

  // Check if the vegetable is harvested
  if (veg.get_isHarvested()) {
    std::cout << "Your vegetable is harvested." << std::endl;
  } else {
    std::cout << "Your vegetable is not yet harvested." << std::endl;
  }

  return 0;
}

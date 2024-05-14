#include <iostream>

#include "seasonalVeg.h"

int main() {
  std::string type;
  int choice;

  // Display menu for selecting vegetable type
  std::cout << "Choose vegetable type:" << std::endl;
  std::cout << "1. Lettuce" << std::endl;
  std::cout << "2. Spinach" << std::endl;
  std::cout << "3. Carrot" << std::endl;
  std::cout << "4. Broccoli" << std::endl;

  // Loop until a valid choice is made
  while (true) {
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    // Set the vegetable type based on the player's choice
    switch (choice) {
      case 1:
        type = "lettuce";
        break;
      case 2:
        type = "spinach";
        break;
      case 3:
        type = "carrot";
        break;
      case 4:
        type = "broccoli";
        break;
      default:
        std::cout << "Invalid choice! Please choose a number between 1 and 4."
                  << std::endl;
        continue;  // Prompt the user again for input
    }
    break;  // Exit the loop if a valid choice is made
  }

  int daysToHarvest;
  std::cout << "Enter days to harvest: ";
  std::cin >> daysToHarvest;

  // Validate user input for the season
  std::string season;
  bool validSeason = false;
  while (!validSeason) {
    std::cout << "Enter the season for the vegetable (spring, summer, autumn, "
                 "winter): ";
    std::cin >> season;

    // Check if the season is valid
    if (season == "spring" || season == "summer" || season == "autumn" ||
        season == "winter") {
      validSeason = true;
    } else {
      std::cout << "Invalid season! Please enter a valid season." << std::endl;
    }
  }

  // Create a SeasonalVeg object based on user input
  seasonalVeg seasonalVegetable("", 0, 0, 0.0, type, daysToHarvest, season);

  // Display seasonal vegetable details
  std::cout << "\nSeasonal Vegetable Details:" << std::endl;
  std::cout << "Type: " << seasonalVegetable.getType() << std::endl;
  std::cout << "Days to Harvest: " << seasonalVegetable.getDaysToHarvest()
            << std::endl;
  std::cout << "Season: " << seasonalVegetable.getSeason() << std::endl;

  // Check if the vegetable is harvested
  if (seasonalVegetable.get_isHarvested()) {
    std::cout << "Your seasonal vegetable is harvested." << std::endl;
  } else {
    std::cout << "Your seasonal vegetable is not yet harvested." << std::endl;
  }

  return 0;
}

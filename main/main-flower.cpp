#include <iostream>
#include <string>

#include "../include/Flower.h"

int main() {
  std::string colour;

  // Display menu for selecting flower colour
  std::cout << "Choose the colour of the flower you want to grow:" << std::endl;
  std::cout << "1. Red" << std::endl;
  std::cout << "2. Blue" << std::endl;
  std::cout << "3. Yellow" << std::endl;
  std::cout << "4. Green" << std::endl;

  int choice;
  bool validChoice = false;

  // Loop until a valid choice is made
  while (!validChoice) {
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Set the colour based on the player's choice
    switch (choice) {
      case 1:
        colour = "Red";
        validChoice = true;
        break;
      case 2:
        colour = "Blue";
        validChoice = true;
        break;
      case 3:
        colour = "Yellow";
        validChoice = true;
        break;
      case 4:
        colour = "Green";
        validChoice = true;
        break;
      default:
        std::cout << "Invalid choice! Please choose a number between 1 and 4."
                  << std::endl;
    }
  }

  // Create a Flower object with the chosen colour
  Flower flower("Flower", 10, 5, 3.5, colour);

  // Display flower details
  std::cout << "You chose to grow a " << colour << " flower." << std::endl;
  std::cout << "Flower Name: " << flower.getName() << std::endl;
  std::cout << "Colour: " << flower.getColour() << std::endl;

  // Check if the flower is harvested
  if (flower.get_isHarvested()) {
    std::cout << "The flower is harvested." << std::endl;
  } else {
    std::cout << "The flower is not yet harvested." << std::endl;
  }
  return 0;
}
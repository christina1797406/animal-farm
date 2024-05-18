#include <iostream>

#include "../Include/Farm.h"
#include "../Include/User.h"

int main() {
  std::cout << "Welcome to the Farming Simulator!" << std::endl;

  // Create a User object
  User user;

  // Ask user for farm name
  std::string farmName;
  std::cout << "Enter a name for your farm: ";
  std::cin >> farmName;

  // Create a Farm object
  Farm farm(farmName, 100, user);  // Starting with 100 coins

  // Provide game instructions
  std::cout << "\nWelcome, " << user.getName() << "!" << std::endl;
  std::cout << "You are " << user.getAge() << " years old." << std::endl;
  std::cout << "Your farm, " << farm.get_farmName() << ", is ready to go!"
            << std::endl;
  std::cout
      << "In this game, you will manage your farm by buying and selling crops, "
      << "refilling your water can, and repairing equipment. Let's start "
         "Farming!"
      << std::endl;

  // Game loop
  bool running = true;
  while (running) {
    std::cout << "\nGame Menu:" << std::endl;
    std::cout << "1. Show game status" << std::endl;
    std::cout << "2. Buy crop" << std::endl;
    std::cout << "3. Sell crop" << std::endl;
    std::cout << "4. Refill water can" << std::endl;
    std::cout << "5. Repair shovel" << std::endl;
    std::cout << "6. Exit" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        farm.show_gameStatus();
        break;
      case 2:
        farm.buyCrop();
        break;
      case 3:
        farm.sellCrop();
        break;
      case 4:
        farm.refillWaterCan();
        break;
      case 5:
        farm.repairShovel();
        break;
      case 6:
        running = false;
        break;
      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }

  std::cout << "Thank you for playing the Farming Simulator!" << std::endl;
  return 0;
}

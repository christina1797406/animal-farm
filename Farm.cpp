// #include "Shovel.h"
#include "Farm.h"

#include <iostream>

Farm::Farm(std::string name, int money, const User& user)
    : farmName(farmName), money(money), numCrops(0), user(user), shovel() {
  // Initialize other attributes and arrays
  // crops = new Crop*[MAX_CROPS]; // MAX_CROPS should be defined
  equipments = new Equipment*[2];  // Assuming 2 is the number of equipments
  equipments[0] = &shovel;         // Assign the shovel to the equipment array
}

Farm::~Farm() {
  // Deallocate memory for crops and equipments
  delete[] crops;
  delete[] equipments;
}

void Farm::set_farmName(std::string name) { this->farmName = farmName; }

std::string Farm::get_farmName() const { return farmName; }

void Farm::setMoney(int money) { this->money = money; }

int Farm::getMoney() const { return money; }

void Farm::setNumCrops(int numCrops) { this->numCrops = numCrops; }

int Farm::getNumCrops() const { return numCrops; }

void Farm::show_gameStatus() const {
  // Print current status of the farm
  std::cout << "User Name: " << user.getName() << std::endl;
  std::cout << "User Age: " << user.getAge() << std::endl;
  std::cout << "Farm Name: " << farmName << std::endl;
  std::cout << "Your Networth: " << money << std::endl;
  std::cout << "Number of Crops: " << numCrops << std::endl;
}

void Farm::buyCrop() {
  std::cout << "Select the crop you want to buy:" << std::endl;
  std::cout << "1. Flower (5 coins)" << std::endl;
  std::cout << "2. Vegetable" << std::endl;
  std::cout << "   a. Lettuce (20 coins)" << std::endl;
  std::cout << "   b. Spinach (15 coins)" << std::endl;
  std::cout << "   c. Carrot (10 coins)" << std::endl;
  std::cout << "   d. Broccoli (15 coins)" << std::endl;

  char choice;
  std::cin >> choice;

  switch (choice) {
    case '1': {
      // Buy flower
      std::cout
          << "Select the color of the flower (white, orange, red, or yellow): ";
      std::string color;
      std::cin >> color;
      if (money >= 5) {
        // Deduct money and add flower to inventory
        money -= 5;
        std::cout << "You bought a " << color << " flower." << std::endl;
        numCrops++;
      } else {
        std::cout << "Not enough money to buy the flower." << std::endl;
      }
      break;
    }
    case '2': {
      // Buy vegetable
      std::cout
          << "Select the vegetable type (Lettuce, Spinach, Carrot, Broccoli): ";
      std::string type;
      std::cin >> type;
      int price = 0;
      if (type == "Lettuce")
        price = 20;
      else if (type == "Spinach")
        price = 15;
      else if (type == "Carrot")
        price = 10;
      else if (type == "Broccoli")
        price = 15;

      if (money >= price) {
        // Deduct money and add vegetable to inventory
        money -= price;
        std::cout << "You bought a " << type << "." << std::endl;
        numCrops++;
      } else {
        std::cout << "Not enough money to buy the vegetable." << std::endl;
      }
      break;
    }
    default:
      std::cout << "Invalid choice." << std::endl;
  }
}

void Farm::sellCrop() {
  if (numCrops == 0) {
    std::cout << "You have no crops to sell." << std::endl;
    return;
  }

  std::cout << "Select the crop you want to sell:" << std::endl;
  std::cout << "1. Flower (20 coins)" << std::endl;
  std::cout << "2. Vegetable" << std::endl;
  std::cout << "   a. Lettuce (30 coins)" << std::endl;
  std::cout << "   b. Spinach (25 coins)" << std::endl;
  std::cout << "   c. Carrot (20 coins)" << std::endl;
  std::cout << "   d. Broccoli (25 coins)" << std::endl;

  char choice;
  std::cin >> choice;

  switch (choice) {
    case '1': {
      if (numCrops > 0) {
        money += 20;
        numCrops--;
        std::cout << "You sold a flower for 20 coins." << std::endl;
      } else {
        std::cout << "You don't have any flowers to sell." << std::endl;
      }
      break;
    }
    case '2': {
      std::string type;
      std::cout << "Select the type of vegetable you want to sell (Lettuce, "
                   "Spinach, Carrot, Broccoli): ";
      std::cin >> type;
      if (numCrops > 0) {
        int price = 0;
        if (type == "Lettuce")
          price = 30;
        else if (type == "Spinach")
          price = 25;
        else if (type == "Carrot")
          price = 20;
        else if (type == "Broccoli")
          price = 25;

        if (price > 0) {
          money += price;
          numCrops--;
          std::cout << "You sold a " << type << " for " << price << " coins."
                    << std::endl;
        } else {
          std::cout << "Invalid vegetable type." << std::endl;
        }
      } else {
        std::cout << "You don't have any " << type << " to sell." << std::endl;
      }
      break;
    }
    default:
      std::cout << "Invalid choice." << std::endl;
  }
}

void Farm::refillWaterCan() {
  double currentLevel = waterCan.waterLevel;
  double spaceAvailable = 6.0 - currentLevel;
  int litresToFill;

  std::cout << "Water can has " << currentLevel << " litres of water."
            << std::endl;
  std::cout << "How many litres would you like to fill? (1 litre costs 5 coins)"
            << std::endl;
  std::cout << "Available space: " << spaceAvailable << " litres." << std::endl;

  // Validate user input
  while (true) {
    std::cout << "Enter the number of litres to fill: ";
    std::cin >> litresToFill;
    if (litresToFill <= spaceAvailable) {
      break;
    } else {
      std::cout << "Not enough space available. Please enter a valid amount."
                << std::endl;
    }
  }

  int cost = litresToFill * 5;
  if (money < cost) {
    std::cout << "Insufficient funds to refill water can." << std::endl;
    return;
  }

  // Deduct money from user
  money -= cost;

  // Refill water can
  waterCan.fillWater(litresToFill);

  std::cout << "Water can successfully refilled with " << litresToFill
            << " litres." << std::endl;
  std::cout << "You have been charged " << cost << " coins." << std::endl;
}

void Farm::repairShovel() {
  if (shovel.getDurability() == 0) {
    // Check if the durability of the shovel is 0
    if (money >= 30) {
      // Check if the player has enough money to pay for the repair
      money -= 30;      // Deduct 30 coins for repair
      shovel.repair();  // Call the repair method of the shovel
      std::cout << "Shovel repaired. You can use it now." << std::endl;
    } else {
      std::cout << "Not enough money to repair the shovel." << std::endl;
    }
  } else {
    std::cout << "Shovel is not damaged. No repair needed." << std::endl;
  }
}

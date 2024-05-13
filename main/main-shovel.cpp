// main-shovel.cpp
#include <iostream>

#include "include/Shovel.h"

int main() {
  int durability;
  std::cout << "Enter the durability of the shovel (maximum 4): ";
  std::cin >> durability;

  Shovel shovel(durability);

  shovel.Use();

  return 0;
}
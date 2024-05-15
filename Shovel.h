// Shovel.h
#ifndef SHOVEL_H
#define SHOVEL_H

#include "Equipment.h"

class Shovel : public Equipment {
 public:
  Shovel();                // Default constructor
  Shovel(int durability);  // Parameterized constructor

  // Method to repair the shovel
  void repair();

  // Method to get the durability of the shovel
  int getDurability() const;

  // Overridden method to use the shovel
  void Use() override;

 private:
  int durability;  // Remaining number of uses available
};

#endif  // SHOVEL_H

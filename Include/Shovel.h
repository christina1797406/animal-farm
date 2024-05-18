// Shovel.h
#ifndef SHOVEL_H
#define SHOVEL_H

#include "Equipment.h"

class Shovel : public Equipment {
 public:
  Shovel();  // Default constructor

  // Method to repair the shovel
  void repair();

  int getDurability() const;  // Getter for durability

  // Overridden method to use the shovel
  void Use() override;

 protected:
  int durability;  // Remaining number of uses available
};

#endif  // SHOVEL_H

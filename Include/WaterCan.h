// WaterCan.h
#ifndef WATERCAN_H
#define WATERCAN_H

#include "Equipment.h"

class WaterCan : public Equipment {
 public:
  WaterCan();                   // Default constructor
  WaterCan(double waterLevel);  // Parameterized constructor

  // Method to fill water in the can
  void fillWater(double amount);

  // Overridden method to use the water can
  void Use() override;

 //protected:
  double waterLevel;  // Water level in the can
};

#endif  // WATERCAN_H

#ifndef VEGETABLE_H
#define VEGETABLE_H
#include <string>

#include "Crop.h"

class Vegetable : public Crop {
 public:
  Vegetable();  // Constructor
  Vegetable(std::string name, int growthRate, int waterNeeded,
            double harvestYield, std::string type, int daysToHarvest);

  // Setter methods for specific attributes
  void setType(std::string type);
  void setDaysToHarvest(int daysToHarvest);

  // Getter methods for specific attributes
  std::string getType() const;
  int getDaysToHarvest() const;

  // Override virtual function from Crop class
  bool get_isHarvested() override;

 private:
  std::string type;   // Type of Vegetable
  int daysToHarvest;  // Number of days to harvest
};

#endif
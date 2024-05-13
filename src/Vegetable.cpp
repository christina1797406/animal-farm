#include "include/Vegetable.h"

Vegetable::Vegetable() : Crop(), type(""), daysToHarvest(0) {}

Vegetable::Vegetable(std::string name, int growthRate, int waterNeeded,
                     double harvestYield, std::string type, int daysToHarvest)
    : Crop(name, growthRate, waterNeeded, harvestYield),
      type(type),
      daysToHarvest(daysToHarvest) {
  // Parameterized constructor
}
// Setter methods
void Vegetable::setType(std::string type) { this->type = type; }

void Vegetable::setDaysToHarvest(int daysToHarvest) {
  this->daysToHarvest = daysToHarvest;
}
// Getter methods
std::string Vegetable::getType() const { return type; }

int Vegetable::getDaysToHarvest() const { return daysToHarvest; }

// Implementation of overriden virtual function from Crop class
bool Vegetable::get_isHarvested() {
  // The vegetable is ready for harvest based on its growth rate
  // Return true if the vegetable is ready for harvest, false otherwise
  const int harvestThreshold = 10;

  // Check if the vegetable has completed required number of growth cycles
  if (growthRate >= harvestThreshold) {
    return true;  // Vegetable is harvested
  } else {
    return false;  // Vegetable is not harvested
  }
}
#include "Flower.h"
// Default constructor
Flower::Flower() : Crop(), colour("") {}
// Parameterized constructor
Flower::Flower(std::string name, int growthRate, int waterNeeded,
               double harvestYield, std::string colour)
    : Crop(name, growthRate, waterNeeded, harvestYield), colour(colour) {}

// Setter for colour
void Flower::setColour(std::string colour) { this->colour = colour; }

// Getter for colour
std::string Flower::getColour() const { return colour; }

bool Flower::get_isHarvested() {
  // A flower is considered harvested if it has reached full bloom
  // A flower is considered to be at full bloom after 5 growth cycles
  // Once it reaches full bloom, it can be harvested
  const int fullBloomThreshold = 5;

  // Check if the flower has completed the required number of growth cycles
  if (growthRate >= fullBloomThreshold) {
    return true;  // Flower is considered harvested
  } else {
    return false;  // Flower is not yet harvested
  }
}

#include "Flower.h"
// Default constructor
Flower::Flower() : Crop(), colour("") {}
// Parameterized constructor
Flower::Flower(std::string name, int growthRate, int waterNeeded,
               double harvestYield, bool isHarvested, std::string colour)
    : Crop(name, growthRate, waterNeeded, harvestYield), colour(colour) {}

// Setter for colour
void Flower::setColour(std::string colour) { this->colour = colour; }

// Getter for colour
std::string Flower::getColour() const { return colour; }
#include "Crop.h"

// Default constructor
Crop::Crop()
    : name(""),
      growthRate(0),
      waterNeeded(0),
      harvestYield(0.0),
      isHarvested(false) {}
// Parameterized constructor
Crop::Crop(std::string name, int growthRate, int waterNeeded,
           double harvestYield)
    : name(name),
      growthRate(growthRate),
      waterNeeded(waterNeeded),
      harvestYield(harvestYield),
      isHarvested(false) {}

// Setter method
void Crop::setName(std::string name) { this->name = name; }

// Getter method
std::string Crop::getName() const { return name; }

void Crop::set_growthRate(int growthRate) { this->growthRate = growthRate; }

int Crop::get_growthRate() const { return growthRate; }

void Crop::set_waterNeeded(int waterNeeded) { this->waterNeeded = waterNeeded; }

int Crop::get_waterNeeded() const { return waterNeeded; }

void Crop::set_harvestYield(double harvestYield) {
  this->harvestYield = harvestYield;
}

double Crop::get_harvestYield() const { return harvestYield; }

// Virtual function implementation

bool Crop::get_isHarvested() { return isHarvested; }
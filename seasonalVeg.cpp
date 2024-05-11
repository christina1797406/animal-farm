#include "seasonalVeg.h"

#include <iostream>  // For cout
#include <string>
// Default constructor
seasonalVeg::seasonalVeg() : Vegetable(), season("") {}
// Parameterized constructor
seasonalVeg::seasonalVeg(std::string name, int growthRate, int waterNeeded,
                         double harvestYield, std::string type,
                         int daysToHarvest, std::string season)
    : Vegetable(name, growthRate, waterNeeded, harvestYield, type,
                daysToHarvest),
      season(season) {}

void seasonalVeg::setSeason(std::string season) { this->season = season; }

std::string seasonalVeg::getSeason() const { return season; }
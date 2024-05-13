#ifndef SEASONALVEG_H
#define SEASONALVEG_H

#include <string>

#include "Vegetable.h"

class seasonalVeg : public Vegetable {
 public:
  seasonalVeg();  // Default constructor
  seasonalVeg(std::string name, int growthRate, int waterNeeded,
              double harvestYield, std::string type, int daysToHarvest,
              std::string season);  // Parameterized constructor

  // Setter method for season
  void setSeason(std::string season);

  // Getter method for season
  std::string getSeason() const;

  // Method to display season
  void displaySeason() const;

 private:
  std::string season;
};

#endif  // SEASONALVEG_H

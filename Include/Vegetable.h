#ifndef VEGETABLE_H
#define VEGETABLE_H
#include <string>

#include <SFML/Graphics.hpp>

#include "Crop.h"

class Vegetable : public Crop {
 public:
  Vegetable();  // Constructor
  Vegetable(std::string name, float growthRate, int waterNeeded,
            double harvestYield, std::string type, float daysToHarvest);

  // Setter methods for specific attributes
  void setType(std::string type);
  void setDaysToHarvest(float daysToHarvest);

  // Getter methods for specific attributes
  std::string getType() const;
  float getDaysToHarvest() const;

  // Override virtual function from Crop class
  bool get_isHarvested() override;

  void plantVegetable(sf::Vector2i pos);

  ~Vegetable() {
    delete(vegSprite);
  }

  sf::Sprite* vegSprite;

 private:
  std::string type;   // Type of Vegetable
  float daysToHarvest;  // Number of days to harvest
};

#endif
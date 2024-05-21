#include "../Include/Vegetable.h"

Vegetable::Vegetable() : Crop(), type(""), daysToHarvest(0) {}

Vegetable::Vegetable(std::string name, float growthRate, int waterNeeded,
                     double harvestYield, std::string type, float daysToHarvest)
    : Crop(name, growthRate, waterNeeded, harvestYield),
      type(type),
      daysToHarvest(daysToHarvest) {
  // Parameterized constructor
}
// Setter methods
void Vegetable::setType(std::string type) { this->type = type; }

void Vegetable::setDaysToHarvest(float daysToHarvest) {
  this->daysToHarvest = daysToHarvest;
}
// Getter methods
std::string Vegetable::getType() const { return type; }

float Vegetable::getDaysToHarvest() const { return daysToHarvest; }

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

void Vegetable::plantVegetable(sf::Vector2i pos) {
  // Create grass sprite
  sf::Sprite* vegetableSprite = new sf::Sprite;
  // Create grass texture
  sf::Texture* vegetable = new sf::Texture;
  {
      // Set dirt texture
      vegetable->loadFromFile("Sprites/Objects/Basic_Plants.png", sf::IntRect(64, 0, 16, 16));

      // Set the dirt sprite texture to the dirt texture
      vegetableSprite->setTexture(*vegetable);
      vegetableSprite->setScale(5, 5);
      //dirtSprite->setTextureRect({ 0, 0, 1920, 1080 });
      vegetableSprite->setPosition(sf::Vector2f(pos));

      vegSprite = vegetableSprite;
    }
}

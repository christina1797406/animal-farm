// Shovel.h
#ifndef SHOVEL_H
#define SHOVEL_H

#include<iostream>

#include <SFML/Graphics.hpp>

#include "Equipment.h"

class Shovel : public Equipment {
 public:
  Shovel();  // Default constructor

  std::string name = "Shovel";

  // Method to repair the shovel
  void repair();

  int getDurability() const;  // Getter for durability

  // Overridden method to use the shovel
  void Use() override;

  sf::Sprite* digHole(sf::Vector2i pos);
  std::string GetName() override;

 protected:
  int durability;  // Remaining number of uses available
};

#endif  // SHOVEL_H

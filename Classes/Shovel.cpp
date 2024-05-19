// Shovel.cpp
#include "../Include/Shovel.h"

#include <SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

Shovel::Shovel() : durability(4) {}

void Shovel::repair() {
  // Repair the shovel by resetting its durability
  durability = 4;
}

int Shovel::getDurability() const { return durability; }

std::string Shovel::GetName() { return name; }

void Shovel::Use() {
  if (durability == 0) {
    std::cout << "Shovel is not durable. Please repair it before using."
              << std::endl;
    // Here you can prompt the user to repair the shovel if needed
  } else {
    std::cout << "Shovel is durable. You can use the shovel." << std::endl;
    durability--;  // Decrement durability after each use
  }
}

sf::Sprite* Shovel::digHole(sf::Vector2i pos) {
  // Create grass sprite
  sf::Sprite* dirtSprite = new sf::Sprite;
  // Create grass texture
  sf::Texture* dirt = new sf::Texture;
  {
      // Set dirt texture
      dirt->loadFromFile("Sprites/Tilesets/Tilled_Dirt.png", sf::IntRect(32, 96, 16, 16));

      // Set the dirt sprite texture to the dirt texture
      dirtSprite->setTexture(*dirt);
      dirtSprite->setScale(5, 5);
      //dirtSprite->setTextureRect({ 0, 0, 1920, 1080 });
      dirtSprite->setPosition(sf::Vector2f(pos));
    }

    return dirtSprite;
}
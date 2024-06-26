#include "../Include/User.h"
#include "../Include/Crop.h"
#include "../Include/Flower.h"

#include "../Include/Equipment.h"
#include "../Include/Shovel.h"
#include "../Include/WaterCan.h"
#include "../Include/CropSeeds.h"
#include "../Include/FlowerSeeds.h"
#include <iostream>

// Default constructor
User::User() {
    Shovel* shovel = new Shovel;
    WaterCan* wateringCan = new WaterCan;
    CropSeeds* seeds = new CropSeeds;

    inventory[0] = shovel;
    inventory[1] = wateringCan;
    inventory[2] = seeds;

    User("User", 0);
}
// Constructor implementation
User::User(std::string _name, int _age): name(_name), age(_age) {
    Shovel* shovel = new Shovel;
    WaterCan* wateringCan = new WaterCan;
    CropSeeds* seeds = new CropSeeds;
    FlowerSeeds* flowerSeeds = new FlowerSeeds;

    // Set items in inventory
    inventory[0] = shovel;
    inventory[1] = wateringCan;
    inventory[2] = seeds;
    inventory[3] = flowerSeeds;
}

// Setter method
void User::setName(std::string name) { this->name = name; }
void User::setAge(int age) { this->age = age; }

// Getter method
std::string User::getName() const { return name; }
int User::getAge() const { return age; }

float User::getWalkSpeed() const { return WALK_SPEED; }
float User::getAnimFramerate() const { return ANIM_FRAMERATE; }

// Draw player
void User::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}
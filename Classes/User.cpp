#include "../Include/User.h"
#include "../Include/GameEntity.h"
#include "../Include/Crop.h"
#include "../Include/Flower.h"

#include "../Include/Equipment.h"
#include "../Include/Shovel.h"
#include "../Include/WaterCan.h"
#include <iostream>

// Default constructor
User::User() {
    Shovel* shovel = new Shovel;
    WaterCan* wateringCan = new WaterCan;

    inventory[0] = shovel;
    inventory[1] = wateringCan;

    User("User", 0);
}
// Constructor implementation
User::User(std::string _name, int _age): name(_name), age(_age) {

    if (!texture.loadFromFile("./sfml/user2.png")) {
        std::cout << "Character file not found." << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(50.0f, 50.0f);
    sprite.setScale(0.3f, 0.3f);
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
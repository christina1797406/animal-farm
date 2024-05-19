#ifndef USER_H
#define USER_H
#include <string>
#include "Flower.h"
#include "Crop.h"
#include "Equipment.h"

#include <SFML/Graphics.hpp>

class User {
    private:
        // Set charcter walk speed (pixels per second, screen is 1920px by 1080px)
        float WALK_SPEED = 500;
        // Set the framerate of the character's animations (time between frames in seconds)
        float ANIM_FRAMERATE = .2;


 public:
  User();                           // constructor
  User(std::string name, int age);

  Equipment** inventory = new Equipment*[10];

  std::vector<Flower*> flowers;
  int flower_size = 10;
  
  // Setter methods
  void setName(std::string name);
  void setAge(int age);

  // Getter method
  std::string getName() const;
  int getAge() const;
  float getWalkSpeed() const;
  float getAnimFramerate() const;

  // Draw player
  void draw(sf::RenderWindow* window);

  // Move the player
  void move_right(int speed) {      // speed is x, 0 is y
      sprite.move(speed,0);
  }
  void move_left(int speed) {
      sprite.move(-speed,0);
  }
  void move_down(int speed) {
      sprite.move(0,speed);
  }
  void move_up(int speed) {
      sprite.move(0,-speed);
  }

  // Plant function
  void plant() {
    // code
    // flowers.push_back(new Flower("/*/"));     // LINE INCOMPLETE
  }

  // more functions..

    sf::Texture** createAnimation() {
        // Allocate memory for a 2D array of sf::Texture pointers
        sf::Texture** characterAnims = new sf::Texture*[4];
        for (int i = 0; i < 4; i++) {
            characterAnims[i] = new sf::Texture[4];
        }

        // Load textures into the array
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                characterAnims[x][y].loadFromFile("Sprites/Characters/basic.png", sf::IntRect(y * 48, x * 48, 48, 48));
            }
        }

        return characterAnims;
    }


 private:
  std::string name;  // user's name
  int age;           // user's age
  
  sf::Texture texture;
  sf::Sprite sprite;
};

#endif
#ifndef USER_H
#define USER_H
#include <string>
#include "Flower.h"
#include "Crop.h"

#include <SFML/Graphics.hpp>

class User {
 public:
  User();                           // constructor
  User(std::string name, int age);

  std::vector<Flower*> flowers;
  int flower_size = 10;
  
  // Setter methods
  void setName(std::string name);
  void setAge(int age);

  // Getter method
  std::string getName() const;
  int getAge() const;

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


 private:
  std::string name;  // user's name
  int age;           // user's age
  
  sf::Texture texture;
  sf::Sprite sprite;
};

#endif
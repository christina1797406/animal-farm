#ifndef FLOWER_H
#define FLOWER_H
#include <string>

#include "Crop.h"

class Flower : public Crop {  // Flower inherits from Crop class
 public:
  Flower();  // Constructor
  Flower(std::string name, int growthRate, int waterNeeded, double harvestYield,
         std::string colour);

  // Setter for colour
  void setColour(std::string colour);
  // Getter for colour
  std::string getColour() const;
  // Override virtual function from Crop class
  bool get_isHarvested() override;

 private:
  std::string colour;  // Colour of flower
};

#endif  // FLOWER_H
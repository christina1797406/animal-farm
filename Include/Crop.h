#ifndef CROP_H
#define CROP_H
#include <string>

class Crop {
 public:
  Crop();  // constructor
  Crop(std::string name, int growthRate, int waterNeeded, double harvestYield);

  void setName(std::string name);  // setter method
  std::string getName() const;     // getter method
  void set_growthRate(float growthRate);
  float get_growthRate() const;
  void set_waterNeeded(int waterNeeded);
  int get_waterNeeded() const;
  void set_harvestYield(double harvestYield);
  double get_harvestYield() const;
  virtual bool
  get_isHarvested();  // virtual function (can be overriden by derived classes)

 protected:
  std::string name;     // name of the crop
  float growthRate;       // growth rate of the crop
  int waterNeeded;      // amount of water needed by crop
  double harvestYield;  // the harvest yield of the crop
};

#endif
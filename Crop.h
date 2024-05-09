#ifndef CROP_H
#define CROP_H
#include <string>

class Crop {
 public:
  Crop();  // constructor
  Crop(std::string name, int growthRate, int waterNeeded, double harvestYield);

  void setName(std::string name);
  std::string getName() const;
  void set_growthRate(int growthRate);
  int get_growthRate() const;
  void set_waterNeeded(int waterNeeded);
  int get_waterNeeded() const;
  void set_harvestYield(double harvestYield);
  double get_harvestYield() const;
  virtual bool get_isHarvested();

 private:
  std::string name;
  int growthRate;
  int waterNeeded;
  double harvestYield;
  bool isHarvested;
};

#endif
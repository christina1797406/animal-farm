#ifndef FARM_H
#define FARM_H

#include <string>

#include "Crop.h"
#include "Equipment.h"
#include "Shovel.h"
#include "User.h"
#include "WaterCan.h"

class Farm {
 protected:
  std::string farmName;
  int money;
  int numCrops;
  User user;
  Crop** crops;
  Equipment** equipments;
  WaterCan waterCan;
  Shovel shovel;  // Add this line

 public:
  Farm(const std::string& farmName, int money, const User& user);
  ~Farm();

  void set_farmName(const std::string& farmName);
  std::string get_farmName() const;

  void setMoney(int money);
  int getMoney() const;

  void setNumCrops(int numCrops);
  int getNumCrops() const;

  void show_gameStatus() const;

  void buyCrop();
  void sellCrop();
  void refillWaterCan();
  void repairShovel();
};

#endif  // FARM_H

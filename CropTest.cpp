#include <iostream>

#include "Crop.h"

class CropTest {
 public:
  void runTests() {
    testSetName();
    testSetGrowthRate();
    testSetWaterNeeded();
    testSetHarvestYield();
    testGetName();
    testGetGrowthRate();
    testGetWaterNeeded();
    testGetHarvestYield();
    testIsHarvested();
  }

 private:
  void testSetName() {
    Crop crop;
    crop.setName("Wheat");
    if (crop.getName() != "Wheat") {
      std::cout << "Test setName failed!" << std::endl;
    }
  }

  void testSetGrowthRate() {
    Crop crop;
    crop.set_growthRate(7);
    if (crop.get_growthRate() != 7) {
      std::cout << "Test setGrowthRate failed!" << std::endl;
    }
  }

  void testSetWaterNeeded() {
    Crop crop;
    crop.set_waterNeeded(15);
    if (crop.get_waterNeeded() != 15) {
      std::cout << "Test setWaterNeeded failed!" << std::endl;
    }
  }

  void testSetHarvestYield() {
    Crop crop;
    crop.set_harvestYield(8.5);
    if (crop.get_harvestYield() != 8.5) {
      std::cout << "Test setHarvestYield failed!" << std::endl;
    }
  }

  void testGetName() {
    Crop crop("Rice", 6, 12, 7.2);
    if (crop.getName() != "Rice") {
      std::cout << "Test getName failed!" << std::endl;
    }
  }

  void testGetGrowthRate() {
    Crop crop("Maize", 8, 14, 9.3);
    if (crop.get_growthRate() != 8) {
      std::cout << "Test getGrowthRate failed!" << std::endl;
    }
  }

  void testGetWaterNeeded() {
    Crop crop("Barley", 5, 10, 6.7);
    if (crop.get_waterNeeded() != 10) {
      std::cout << "Test getWaterNeeded failed!" << std::endl;
    }
  }

  void testGetHarvestYield() {
    Crop crop("Soybean", 4, 8, 5.1);
    if (crop.get_harvestYield() != 5.1) {
      std::cout << "Test getHarvestYield failed!" << std::endl;
    }
  }

  void testIsHarvested() {
    Crop crop;
    if (crop.get_isHarvested() != false) {
      std::cout << "Test isHarvested failed!" << std::endl;
    }
  }
};

int main() {
  CropTest cropTest;
  cropTest.runTests();

  return 0;
}

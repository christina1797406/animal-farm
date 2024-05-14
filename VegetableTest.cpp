#include <iostream>

#include "Vegetable.h"

class VegetableTest {
 public:
  void runTests() {
    testSetType();
    testGetType();
    testSetDaysToHarvest();
    testGetDaysToHarvest();
    testIsHarvested();
  }

 private:
  void testSetType() {
    Vegetable veg;
    veg.setType("Carrot");
    if (veg.getType() != "Carrot") {
      std::cout << "Test setType failed!" << std::endl;
    }
  }

  void testGetType() {
    Vegetable veg("Tomato", 5, 3, 2.5, "Tomato", 10);
    if (veg.getType() != "Tomato") {
      std::cout << "Test getType failed!" << std::endl;
    }
  }

  void testSetDaysToHarvest() {
    Vegetable veg;
    veg.setDaysToHarvest(7);
    if (veg.getDaysToHarvest() != 7) {
      std::cout << "Test setDaysToHarvest failed!" << std::endl;
    }
  }

  void testGetDaysToHarvest() {
    Vegetable veg("Potato", 5, 3, 2.5, "Potato", 15);
    if (veg.getDaysToHarvest() != 15) {
      std::cout << "Test getDaysToHarvest failed!" << std::endl;
    }
  }

  void testIsHarvested() {
    // Test if a vegetable is harvested after reaching full growth
    Vegetable veg("Cabbage", 10, 5, 3.5, "Cabbage", 20);
    if (!veg.get_isHarvested()) {
      std::cout << "Test isHarvested failed!" << std::endl;
    }
  }
};

int main() {
  VegetableTest vegTest;
  vegTest.runTests();

  return 0;
}

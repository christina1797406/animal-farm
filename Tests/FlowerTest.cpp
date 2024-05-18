#include <iostream>

#include "../Include/Flower.h"

class FlowerTest {
 public:
  void runTests() {
    testSetColour();
    testGetColour();
    testIsHarvested();
  }

 private:
  void testSetColour() {
    Flower flower;
    flower.setColour("Red");
    if (flower.getColour() != "Red") {
      std::cout << "Test setColour failed!" << std::endl;
    }
  }

  void testGetColour() {
    Flower flower("Rose", 5, 3, 2.5, "Yellow");
    if (flower.getColour() != "Yellow") {
      std::cout << "Test getColour failed!" << std::endl;
    }
  }

  void testIsHarvested() {
    // Test if a flower is harvested after reaching full bloom
    Flower flower("Lily", 5, 3, 2.5, "White");
    if (!flower.get_isHarvested()) {
      std::cout << "Test isHarvested failed!" << std::endl;
    }
  }
};

int main() {
  FlowerTest flowerTest;
  flowerTest.runTests();

  return 0;
}

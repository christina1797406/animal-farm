#include <iostream>

#include "Shovel.h"

class ShovelTest {
 public:
  void runTests() {
    testRepair();
    testUse();
  }

 private:
  void testRepair() {
    Shovel shovel;
    shovel.repair();
    if (shovel.getDurability() != 4) {
      std::cout << "Test repair failed!" << std::endl;
    } else {
      std::cout << "Test repair passed!" << std::endl;
    }
  }

  void testUse() {
    Shovel shovel;
    shovel.repair();
    std::cout << "Testing with durability = 4:" << std::endl;
    shovel.Use();
    if (shovel.getDurability() != 3) {
      std::cout << "Test use failed!" << std::endl;
    } else {
      std::cout << "Test use passed!" << std::endl;
    }

    Shovel brokenShovel;
    for (int i = 0; i < 4; ++i) {
      brokenShovel.Use();
    }
    std::cout << "Testing with durability = 0:" << std::endl;
    brokenShovel.Use();
    if (brokenShovel.getDurability() != 0) {
      std::cout << "Test broken shovel use failed!" << std::endl;
    } else {
      std::cout << "Test broken shovel use passed!" << std::endl;
    }
  }
};

int main() {
  ShovelTest shovelTest;
  shovelTest.runTests();

  return 0;
}

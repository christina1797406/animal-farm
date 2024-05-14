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
    Shovel shovel(2);
    shovel.repair();
    if (shovel.get_no_of_equipment() != 4) {
      std::cout << "Test repair failed!" << std::endl;
    }
  }

  void testUse() {
    Shovel shovel(3);
    std::cout << "Testing with durability = 3:" << std::endl;
    shovel.Use();
    std::cout << std::endl;

    Shovel brokenShovel(0);
    std::cout << "Testing with durability = 0:" << std::endl;
    brokenShovel.Use();
    std::cout << std::endl;
  }
};

int main() {
  ShovelTest shovelTest;
  shovelTest.runTests();

  return 0;
}

#include <iostream>

#include "../Include/WaterCan.h"

class WaterCanTest {
 public:
  void runTests() {
    testFillWater();
    testUse();
  }

 private:
  void testFillWater() {
    WaterCan waterCan;
    waterCan.fillWater(4.0);
    if (waterCan.get_no_of_equipment() != 4) {
      std::cout << "Test fillWater failed!" << std::endl;
    }
  }

  void testUse() {
    WaterCan emptyWaterCan;
    std::cout << "Testing with empty water can:" << std::endl;
    emptyWaterCan.Use();
    std::cout << std::endl;

    WaterCan lowWaterCan(1.0);
    std::cout << "Testing with low water can:" << std::endl;
    lowWaterCan.Use();
    std::cout << std::endl;

    WaterCan halfFullWaterCan(3.0);
    std::cout << "Testing with half-full water can:" << std::endl;
    halfFullWaterCan.Use();
    std::cout << std::endl;

    WaterCan fullWaterCan(6.0);
    std::cout << "Testing with full water can:" << std::endl;
    fullWaterCan.Use();
    std::cout << std::endl;
  }
};

int main() {
  WaterCanTest waterCanTest;
  waterCanTest.runTests();

  return 0;
}

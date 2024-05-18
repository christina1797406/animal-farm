#include <iostream>

#include "../Include/Shovel.h"
#include "../Include/WaterCan.h"

class EquipmentTest {
 public:
  void runTests() {
    testSetNoOfEquipment();
    testGetNoOfEquipment();
  }

 private:
  void testSetNoOfEquipment() {
    WaterCan waterCan;  // Creating an instance of WaterCan instead of Equipment
    waterCan.set_no_of_equipment(5);
    if (waterCan.get_no_of_equipment() != 5) {
      std::cout << "Test set_no_of_equipment failed!" << std::endl;
    }
  }

  void testGetNoOfEquipment() {
    Shovel shovel;  // Creating an instance of Shovel instead of Equipment
    shovel.set_no_of_equipment(10);
    if (shovel.get_no_of_equipment() != 10) {
      std::cout << "Test get_no_of_equipment failed!" << std::endl;
    }
  }
};

int main() {
  EquipmentTest equipTest;
  equipTest.runTests();

  return 0;
}

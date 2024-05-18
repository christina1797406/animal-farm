#include <iostream>

#include "../Include/seasonalVeg.h"

class SeasonalVegTest {
 public:
  void runTests() {
    testSetSeason();
    testGetSeason();
  }

 private:
  void testSetSeason() {
    seasonalVeg veg;
    veg.setSeason("Spring");
    if (veg.getSeason() != "Spring") {
      std::cout << "Test setSeason failed!" << std::endl;
    }
  }

  void testGetSeason() {
    seasonalVeg veg("Potato", 5, 3, 2.5, "Potato", 15, "Summer");
    if (veg.getSeason() != "Summer") {
      std::cout << "Test getSeason failed!" << std::endl;
    }
  }
};

int main() {
  SeasonalVegTest vegTest;
  vegTest.runTests();

  return 0;
}

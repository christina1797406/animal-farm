#include "Shovel.h"
#include "WaterCan.h"

int main() {
  // Create instances of WaterCan and Shovel
  WaterCan waterCan;
  Shovel shovel;

  // Set the number of equipment for each instance
  waterCan.set_no_of_equipment(3);
  shovel.set_no_of_equipment(2);

  // Use the equipment (virtual function) for each instance
  waterCan.Use();  // This will call the overridden function in WaterCan
  shovel.Use();    // This will call the overridden function in Shovel

  return 0;
}

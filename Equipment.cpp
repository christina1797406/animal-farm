#include "Equipment.h"

// Constructor
Equipment::Equipment() : no_of_equipment(0) {}

Equipment::Equipment(int no_of_equipment) : no_of_equipment(no_of_equipment) {}

// Setter method for number of equipment
void Equipment::set_no_of_equipment(int count) {
  this->no_of_equipment = count;
}

// Getter method for numbe rof equipment
int Equipment::get_no_of_equipment() const { return no_of_equipment; }
#include "../Include/Equipment.h"

Equipment::Equipment() : no_of_equipment(0) {}

Equipment::Equipment(int no_of_equipment) : no_of_equipment(no_of_equipment) {}

void Equipment::set_no_of_equipment(int count) {
  this->no_of_equipment = count;
}

int Equipment::get_no_of_equipment() const { return no_of_equipment; }
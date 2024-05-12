#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <string>

class Equipment {
 public:
  Equipment();  // Constructor
  Equipment(int no_of_equipment);

  // Getter for number of equipment
  void set_no_of_equipment(int count);
  // Getter for number of equipment
  int get_no_of_equipment() const;
  // virtual function
  virtual void Use() = 0;

 protected:
  int no_of_equipment;  // Number of equipment
};

#endif
#ifndef USER_H
#define USER_H
#include <string>

class User {
 public:
  User();  // constructor
  User(std::string name, int age);
  // Setter methods
  void setName(std::string name);
  void setAge(int age);

  // Getter method
  std::string getName() const;
  int getAge() const;

 private:
  std::string name;  // user's name
  int age;           // user's age
};

#endif
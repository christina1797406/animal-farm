#include <iostream>

#include "User.h"

class UserTest {
 public:
  void runTests() {
    testSetName();
    testSetAge();
    testGetName();
    testGetAge();
  }

 private:
  void testSetName() {
    User user;
    user.setName("Alice");
    if (user.getName() != "Alice") {
      std::cout << "Test setName failed!" << std::endl;
    }
  }

  void testSetAge() {
    User user;
    user.setAge(25);
    if (user.getAge() != 25) {
      std::cout << "Test setAge failed!" << std::endl;
    }
  }

  void testGetName() {
    User user("Bob", 30);
    if (user.getName() != "Bob") {
      std::cout << "Test getName failed!" << std::endl;
    }
  }

  void testGetAge() {
    User user("Charlie", 35);
    if (user.getAge() != 35) {
      std::cout << "Test getAge failed!" << std::endl;
    }
  }
};

int main() {
  UserTest userTest;
  userTest.runTests();

  return 0;
}

// main-shovel.cpp
#include <iostream>

#include "Shovel.h"

int main() {
  Shovel shovel;

  for (int i = 0; i < 5; ++i) {  // Simulate using the shovel 4 times
    shovel.Use();
  }

  return 0;
}
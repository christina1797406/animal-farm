// Shovel.h
#ifndef FLOWERSEEDS_H
#define FLOWERSEEDS_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Equipment.h"

class FlowerSeeds : public Equipment {
    public:
        FlowerSeeds();  // Default constructor
        std::string name = "Flower Seeds";
        std::string GetName() override;
        void Use() override;
};

#endif  // FLOWERSEEDS_H

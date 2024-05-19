// Shovel.h
#ifndef CROPSEEDS_H
#define CROPSEEDS_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include "Equipment.h"

class CropSeeds : public Equipment {
    public:
        CropSeeds();  // Default constructor
        std::string name = "Seeds";
        std::string GetName() override;
        void Use() override;
};

#endif  // CROPSEEDS_H

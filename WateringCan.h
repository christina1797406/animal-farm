#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "Equipment.h"

class WateringCan : public Equipment {
    private:
        int volume;
        int water;

        
    public:
        WateringCan();
        void use() {}
        
        ~WateringCan();
};


#endif
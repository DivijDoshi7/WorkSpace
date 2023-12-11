// Car.h
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(); // Constructor
    int getGear() const; // Getter for gear
};

#endif

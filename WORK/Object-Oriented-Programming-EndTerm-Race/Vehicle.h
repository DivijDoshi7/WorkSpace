// Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

class Car; // Forward declaration of Car class

class Vehicle {
    friend class Car; // Declare Car as a friend class to access protected members

protected:
    int speed;
    int gear;

public:
    Vehicle();
    void accelerate(int increment);
    void brake(int decrement);
    void shiftGear(int newGear);
    void displayInfo() const;
    int getSpeed() const;
    int getGear() const; // Add a protected getter for gear
};

#endif

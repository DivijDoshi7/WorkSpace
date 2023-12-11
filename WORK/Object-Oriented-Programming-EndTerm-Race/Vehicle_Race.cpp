// Vehicle.cpp
#include "Vehicle.h"
#include <iostream>
#include <stdexcept>
#include <cassert>

Vehicle::Vehicle() : speed(0), gear(1) {}

int Vehicle::getSpeed() const {
    return speed;
}

int Vehicle::getGear() const {
    return gear;
}

void Vehicle::accelerate(int increment) {
    try {
        if (increment <= 0) {
            throw std::invalid_argument("Invalid acceleration value. Must be greater than 0.");
        }
        speed += increment;
        std::cout << "Accelerating by " << increment << " mph." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Vehicle::brake(int decrement) {
    try {
        if (decrement <= 0) {
            throw std::invalid_argument("Invalid braking value. Must be greater than 0.");
        }
        speed -= decrement;
        std::cout << "Applying brakes by " << decrement << " mph." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Vehicle::shiftGear(int newGear) {
    try {
        assert(newGear >= 1 && newGear <= 5);
        if (newGear < 1 || newGear > 5) {
            throw std::invalid_argument("Invalid gear value. Must be between 1 and 5.");
        }
        gear = newGear;
        std::cout << "Shifting to gear " << newGear << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Vehicle::displayInfo() const {
    std::cout << "Current Speed: " << speed << " mph, Current Gear: " << gear << std::endl;
}

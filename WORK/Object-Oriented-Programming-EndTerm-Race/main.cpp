#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int numCars = 4;
    std::vector<Car> cars(numCars);

    int raceDistance = 1000;
    bool raceOver = false;
    bool halfwayReached = false;

    while (!raceOver) {
        system("clear"); // Clear the console (for Linux/macOS)
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay for visualization

        // Simulate each car's actions (accelerate, brake, shift gear)
        for (int i = 0; i < numCars; ++i) {
            int choice = std::rand() % 3 + 1; // Random choice: 1 = Accelerate, 2 = Brake, 3 = Shift Gear
            int value = std::rand() % 20 + 1; // Random value (e.g., acceleration, braking)

            switch (choice) {
                case 1:
                    cars[i].accelerate(value);
                    break;
                case 2:
                    cars[i].brake(10); // Brake with a fixed value of 10 mph
                    break;
                case 3:
                    cars[i].shiftGear(std::rand() % 5 + 1); // Random gear shift (1-5)
                    break;
            }

            if (cars[i].getSpeed() < 10) {
                cars[i].accelerate(10); // Accelerate if speed is less than 10 mph
            } else if (cars[i].getSpeed() > 150) {
                cars[i].brake(10); // Apply brakes if speed exceeds 150 mph
            }

            // Display car information at a specific time and halfway point (500 miles)
            if (!halfwayReached && raceDistance <= 500) {
                halfwayReached = true;
                std::cout << "Properties at halfway point (500 miles):" << std::endl;
                for (int j = 0; j < numCars; ++j) {
                    std::cout << "Car " << j + 1 << ": ";
                    cars[j].displayInfo();
                }
            }

            std::cout << "Car " << i + 1 << ": ";
            cars[i].displayInfo();
        }

        raceDistance -= 50; // Decrease the race distance

        if (raceDistance <= 0) {
            raceOver = true;
        }
    }

    std::cout << "Race over! All cars have crossed the finish line." << std::endl;
    std::cout << "The Properties are shown at half race distance." << std::endl;

    return 0;
}

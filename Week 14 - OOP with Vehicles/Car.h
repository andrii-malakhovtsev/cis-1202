#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(const string &manufacturer = "", int yearBuilt = 0, int numberOfDoors = 0);
    int getNumberOfDoors() const;
    void setNumberOfDoors(int numberOfDoors);
    void displayInfo() const override;
};

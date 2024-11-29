// Andrii Malakhovtsev
// CIS 1202 501
// November 28, 2024

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

#pragma once

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    int towingCapacity;

public:
    Truck(const string &manufacturer = "", int yearBuilt = 0, int towingCapacity = 0);
    int getTowingCapacity() const;
    void setTowingCapacity(int towingCapacity);
    void displayInfo() const override;
};

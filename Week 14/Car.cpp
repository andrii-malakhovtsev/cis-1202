// Andrii Malakhovtsev
// CIS 1202 501
// November 28, 2024

#include "Car.h"
#include <iostream>

Car::Car(const string &manufacturer, int yearBuilt, int numberOfDoors) : Vehicle(manufacturer, yearBuilt), numberOfDoors(numberOfDoors) {}

int Car::getNumberOfDoors() const {
    return numberOfDoors;
}

void Car::setNumberOfDoors(int numberOfDoors) {
    this->numberOfDoors = numberOfDoors;
}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    cout << "Number of Doors: " << numberOfDoors << endl;
}

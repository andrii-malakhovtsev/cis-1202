// Andrii Malakhovtsev
// CIS 1202 501
// November 26, 2024

#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(const string& manufacturer, int yearBuilt) 
    : manufacturer(manufacturer), yearBuilt(yearBuilt) {}

string Vehicle::getManufacturer() const {
    return manufacturer;
}

int Vehicle::getYearBuilt() const {
    return yearBuilt;
}

void Vehicle::setManufacturer(const string& manufacturer) {
    this->manufacturer = manufacturer;
}

void Vehicle::setYearBuilt(int yearBuilt) {
    this->yearBuilt = yearBuilt;
}

void Vehicle::displayInfo() const {
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Year Built: " << yearBuilt << endl;
}


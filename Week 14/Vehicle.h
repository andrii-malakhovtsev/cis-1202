// Andrii Malakhovtsev
// CIS 1202 501
// November 26, 2024

#pragma once

#include <string>

using namespace std;

class Vehicle {
protected:
    string manufacturer;
    int yearBuilt;

public:
    Vehicle(const string& manufacturer = "", int yearBuilt = 0);

    string getManufacturer() const;
    int getYearBuilt() const;

    void setManufacturer(const string &manufacturer);
    void setYearBuilt(int yearBuilt);

    virtual void displayInfo() const;
};

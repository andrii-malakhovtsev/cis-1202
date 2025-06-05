#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

using namespace std;

void enterVehicleInfo(string &, int &, bool = false);

int main() {
    string manufacturer;
    int yearBuilt;

    cout << "Vehicle Program\n\n";

    cout << "Vehicle:\n";
    enterVehicleInfo(manufacturer, yearBuilt, true);
    
    Vehicle vehicle(manufacturer, yearBuilt);
    cout << "\nVehicle Information:\n";
    vehicle.displayInfo();

    cout << "\nCar:\n";
    enterVehicleInfo(manufacturer, yearBuilt);

    int numberOfDoors;
    cout << "Enter the number of doors: ";
    cin >> numberOfDoors;

    Car car(manufacturer, yearBuilt, numberOfDoors);
    cout << "\nCar Information:\n";
    car.displayInfo();

    cout << "\nTruck:\n";
    enterVehicleInfo(manufacturer, yearBuilt);

    int towingCapacity;
    cout << "Enter the towing capacity: ";
    cin >> towingCapacity;

    Truck truck(manufacturer, yearBuilt, towingCapacity);
    cout << "\nTruck Information:\n";
    truck.displayInfo();

    return 0;
}

void enterVehicleInfo(string &manufacturer, int &yearBuilt, bool firstEnter)
{
    cout << "Enter the manufacturer: ";
    if (!firstEnter) cin.ignore();
    getline(cin, manufacturer);
    cout << "Enter the year built: ";
    cin >> yearBuilt;
}
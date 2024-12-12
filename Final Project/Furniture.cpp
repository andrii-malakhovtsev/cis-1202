#include "Furniture.h"

Furniture::Furniture(const string& name, double price, const string& material)
    : Item(name, price), material(material) {}

void Furniture::display() const {
    cout << "Furniture: " << name << " | Material: " << material
        << " | Price: $" << price << endl;
}
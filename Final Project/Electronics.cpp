#include "Electronics.h"

Electronics::Electronics(const string& itemName, double itemPrice, const string& itemBrand)
    : Item(itemName, itemPrice), brand(itemBrand) {}

void Electronics::display() const {
    cout << "Electronics: " << name << " | Brand: " << brand
        << " | Price: $" << price << endl;
}
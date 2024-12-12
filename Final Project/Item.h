#pragma once

#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string name;
    double price;

public:
    Item(const string& itemName = "", double itemPrice = 0.0);

    virtual void display() const = 0;

    virtual ~Item() {}
};

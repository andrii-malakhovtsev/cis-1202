#pragma once

#include "Item.h"

class Electronics : public Item {
private:
    string brand;

public:
    Electronics(const string& itemName, double itemPrice, const string& itemBrand);

    void display() const override;

    ~Electronics() {}
};
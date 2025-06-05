#pragma once

#include "Item.h"

class Furniture : public Item {
private:
    string material;

public:
    Furniture(const string& name, double price, const string& material);

    void display() const override;

    ~Furniture() {}
};

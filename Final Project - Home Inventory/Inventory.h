#pragma once

#include "Item.h"
#include <vector>
using namespace std;

class Inventory {
private:
    vector<Item*> items;

public:
    void addItem(Item* item);
    void displayAll() const;

    ~Inventory();
};

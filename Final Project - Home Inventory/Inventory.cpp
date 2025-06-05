#include "Inventory.h"

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

void Inventory::displayAll() const {
    for (const auto& item : items) {
        item->display();
    }
}

Inventory::~Inventory() {
    for (auto item : items) {
        delete item;
    }
}
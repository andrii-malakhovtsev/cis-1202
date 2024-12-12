#pragma once

#include "Item.h"

class Book : public Item {
private:
    string author;

public:
    Book(const string& title, double price, const string& author);

    void display() const override;

    ~Book() {}
};
#include "Book.h"

Book::Book(const string& title, double price, const string& author)
    : Item(title, price), author(author) {}

void Book::display() const {
    cout << "Book: " << name << " | Author: " << author
        << " | Price: $" << price << endl;
}
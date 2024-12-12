#include <iostream>
#include <vector>
#include <limits>
#include "Item.h"
#include "Electronics.h"
#include "Book.h"
#include "Furniture.h"
#include "Inventory.h"

using namespace std;

void addItemsDynamically(Inventory&);
double getValidPriceInput(const string&);

int main() {
    Inventory myInventory;

    cout << "=== Welcome to the Home Inventory System ===\n";

    while (true) {
        addItemsDynamically(myInventory);

        cout << "\n=== Your inventory ===\n";
        myInventory.displayAll();

        char choice;
        cout << "\nDo you want to add more items? (Y/N): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}

void addItemsDynamically(Inventory& inventory) {

    const int STOP_ADDING_ITEMS_MENU_NUMBER = 4;
    int choice;

    while (true) {
        cout << "\nChoose an item to add:\n";
        cout << "1. Electronics\n";
        cout << "2. Book\n";
        cout << "3. Furniture\n";
        cout << STOP_ADDING_ITEMS_MENU_NUMBER << ". Stop Adding Items\n";
        cout << "Enter your choice (1-" << STOP_ADDING_ITEMS_MENU_NUMBER << "): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > STOP_ADDING_ITEMS_MENU_NUMBER) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please, try again.\n";
            continue;
        }

        if (choice == STOP_ADDING_ITEMS_MENU_NUMBER) break;

        cout << endl;
        switch (choice) {
        case 1: {
            string name, brand;
            double price;

            cout << "Enter the name of the electronics: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter the brand: ";
            getline(cin, brand);

            price = getValidPriceInput("Enter the price: $");
            inventory.addItem(new Electronics(name, price, brand));
            break;
        }
        case 2: {
            string title, author;
            double price;

            cout << "Enter the title of the book: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter the author: ";
            getline(cin, author);

            price = getValidPriceInput("Enter the price: $");
            inventory.addItem(new Book(title, price, author));
            break;
        }
        case 3: {
            string name, material;
            double price;

            cout << "Enter the name of the furniture: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter the material: ";
            getline(cin, material);

            price = getValidPriceInput("Enter the price: $");
            inventory.addItem(new Furniture(name, price, material));
            break;
        }
        default:
            cout << "Invalid choice. Please, try again.\n";
        }
    }
}

double getValidPriceInput(const string& prompt) {
    double price;
    while (true) {
        cout << prompt;
        cin >> price;

        if (cin.fail() || price <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid price. Please, enter a valid number.\n";
        }
        else {
            break;
        }
    }
    return price;
}

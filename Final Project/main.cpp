#include <iostream>
#include <vector>
#include "Item.h"
#include "Electronics.h"
#include "Book.h"
#include "Furniture.h"
#include "Inventory.h"

using namespace std;

void addItemsDynamically(Inventory&);

int main() {
    Inventory myInventory;

    cout << "=== Welcome to the Home Inventory System ===\n";

    while (true) {
        addItemsDynamically(myInventory);

        cout << "\nYour inventory:\n";
        myInventory.displayAll();

        char choice;
        cout << "Do you want to add more items? (Y/N): ";
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
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == STOP_ADDING_ITEMS_MENU_NUMBER) break;

        switch (choice) {
        case 1: {
            string name, brand;
            double price;

            cout << "Enter the name of the electronics: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter the brand: ";
            getline(cin, brand);

            cout << "Enter the price: ";
            cin >> price;

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

            cout << "Enter the price: ";
            cin >> price;

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
            
            cout << "Enter the price: ";
            cin >> price;

            inventory.addItem(new Furniture(name, price, material));
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

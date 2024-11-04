// Andrii Malakhovtsev
// CIS 1202 501
// November 3, 2024

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Product
{
    long number;
    char name[40];
    double price;
    int quantity;
};

int showMenu();
void createFile(fstream&);
void displayFile(fstream&);
void displayRecord(fstream&, int);
void modifyRecord(fstream&);

int main()
{
    fstream file("inventory.dat", ios::in | ios::out | ios::binary | ios::trunc);
    createFile(file);

    int choice;
    do
    {
        choice = showMenu();
        switch (choice)
        {
        case 1:
            displayFile(file);
            break;
        case 2:
        {
            int recordNum;
            cout << "Enter the record number to display: ";
            cin >> recordNum;
            displayRecord(file, recordNum);
            break;
        }
        case 3:
            modifyRecord(file);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    file.close();
    return 0;
}

int showMenu()
{
    int choice;
    cout << "--- Product Inventory ---\n";
    cout << "1. Display entire inventory\n";
    cout << "2. Display a particular product\n";
    cout << "3. Modify a product\n";
    cout << "4. Exit\n";
    cout << "Please, enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4)
    {
        cout << "Invalid choice. Please, enter a number between 1 and 4: ";
        cin >> choice;
    }
    return choice;
}

void createFile(fstream& f)
{
    Product products[] =
    {
        {12345, "Dog", 11.99, 5},
        {67890, "Cat", 9.99, 3},
        {11121, "Bird", 5.49, 10},
        {32415, "Fish", 2.99, 20},
        {16371, "Squid", 13.20, 2}
    };

    for (const auto& p : products)
    {
        f.write(reinterpret_cast<const char*>(&p), sizeof(p));
    }
    f.flush();
}

void displayFile(fstream& f)
{
    f.clear();
    f.seekg(0);

    Product p;
    int recordNum = 0;

    cout << "\n--- Inventory ---\n";
    while (f.read(reinterpret_cast<char*>(&p), sizeof(p)))
    {
        displayRecord(f, recordNum);
        recordNum++;
    }
}

void displayRecord(fstream& f, int recordNum)
{
    f.clear();
    f.seekg(recordNum * sizeof(Product));

    Product p;
    if (f.read(reinterpret_cast<char*>(&p), sizeof(p)))
    {
        cout << "\n--- Product Details ---\n";
        cout << "Record: #" << recordNum << "\n"
            << "Number #: " << p.number << "\n"
            << "Name: " << p.name << "\n"
            << "Price: $" << p.price << "\n"
            << "Quantity: " << p.quantity << endl;
    }
    else
    {
        cout << "Record not found." << endl;
    }
    cout << endl;
}

void modifyRecord(fstream& f)
{
    const int NAME_SIZE = 40;

    int recordNum;
    cout << "Enter the record number to modify: ";
    cin >> recordNum;

    f.clear();
    f.seekg((recordNum) * sizeof(Product));

    Product p;
    if (f.read(reinterpret_cast<char*>(&p), sizeof(p)))
    {
        cout << "--- Current product details ---\n"
            << "Number: " << p.number << "\n"
            << "Name: " << p.name << "\n"
            << "Price: $" << p.price << "\n"
            << "Quantity: " << p.quantity << endl;

        cout << "Enter new name: ";
        cin.ignore();
        cin.getline(p.name, NAME_SIZE);
        cout << "Enter new price: ";
        cin >> p.price;
        cout << "Enter new quantity: ";
        cin >> p.quantity;

        f.seekp(-static_cast<int>(sizeof(p)), ios::cur);
        f.write(reinterpret_cast<const char*>(&p), sizeof(p));
        cout << "Product updated successfully." << endl;
    }
    else
    {
        cout << "Product not found." << endl;
    }
}

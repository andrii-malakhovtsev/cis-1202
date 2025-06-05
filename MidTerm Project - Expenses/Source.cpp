#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

struct Expense 
{
    string category;
    double amount;
    string date;
};

int menu();
bool isValidDate(string&);
void addExpense(Expense*, int&);
bool dateValidEntry(string& date);
void displayExpenses(Expense*, int);
void sortExpenses(Expense*, int);
void searchExpense(const Expense*, int);

int main()
{
    const int MAX_EXPENSES = 100;
    Expense expenses[MAX_EXPENSES];
    const int LAST_MENU_ITEM_NUMBER = 5;
    int expenseCount = 0;

    int choice;
    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            addExpense(expenses, expenseCount);
            break;
        case 2:
            displayExpenses(expenses, expenseCount);
            break;
        case 3:
            sortExpenses(expenses, expenseCount);
            break;
        case 4:
            searchExpense(expenses, expenseCount);
            break;
        case LAST_MENU_ITEM_NUMBER:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Please try again.";
        }

        cout << "\n";

    } while (choice != LAST_MENU_ITEM_NUMBER);

    // End
    cout << endl << endl;
    system("pause");
    return 0;
}

int menu()
{
    const int FIRST_MENU_ITEM_NUMBER = 1, LAST_MENU_ITEM_NUMBER = 5;

    cout << "1. Add Expense\n";
    cout << "2. Display Expenses\n";
    cout << "3. Sort Expenses (by amount)\n";
    cout << "4. Search Expenses\n";
    cout << "5. Exit\n";
    cout << "Enter selection: ";

    int chosenOption;
    cin >> chosenOption;
    cin.ignore();

    while (chosenOption < FIRST_MENU_ITEM_NUMBER || chosenOption > LAST_MENU_ITEM_NUMBER)
    {
        cout << "Invalid seleciton. Please enter a number between " 
            << FIRST_MENU_ITEM_NUMBER << '-' << LAST_MENU_ITEM_NUMBER << ": ";

        cin >> chosenOption;
    }

    return chosenOption;
}

bool isValidDate(string& date) 
{
    const int MAX_DATE_LENGTH = 10;

    if (date.length() != MAX_DATE_LENGTH) 
    {
        return false;  // Date length must be exactly 10
    }

    // Check the date format MM-DD-YYYY
    int firstDashDateFormatPosition = 2, secondDashDateFormatPosition = 5;

    for (size_t i = 0; i < date.length(); ++i) 
    {
        if (i == firstDashDateFormatPosition || i == secondDashDateFormatPosition)
        {
            if (date[i] != '-')
            {
                return false;  // Dashes must be at positions 2 and 5
            }
        }
        else if (!isdigit(date[i])) 
        {
            return false;  // All other characters must be digits
        }
    }

    int month = stoi(date.substr(0, 2));  // MM
    int day = stoi(date.substr(3, 2));    // DD
    int year = stoi(date.substr(6, 4));   // YYYY

    const int MAX_MONTHS = 12;
    const int MAX_DAYS = 31;

    // Validate month and day ranges
    if (month < 1 || month > MAX_MONTHS || day < 1 || day > MAX_DAYS) {
        return false;
    }

    return true;
}

bool dateValidEntry(string& date) 
{
    cout << "Enter date (MM-DD-YYYY): ";
    getline(cin, date);

    if (!isValidDate(date))
    {
        cout << "Wrong date format. Please, try again.\n";
        return false;
    }
    return true;
}

void addExpense(Expense* expenses, int& count)
{
    const int MAX_EXPENSES = 100;
    if (count < MAX_EXPENSES)
    {
        cout << "Enter expense category (string): ";
        getline(cin, expenses[count].category);

        cout << "Enter expense amount: ";
        cin >> expenses[count].amount;
        cin.ignore(); // Clear newline character from input buffer

        bool correctDateFormat;
        do
        {
            correctDateFormat = dateValidEntry(expenses[count].date);
        } while (correctDateFormat == false);

        count++; // Increase total amount of expenses
        cout << "Expense added!\n";
    }
    else 
    {
        cout << "Expense list is full.\n";
    }
}

void displayExpenses(Expense* expenses, int count) 
{
    if (count == 0) 
    {
        cout << "No expenses to display.\n\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Category\tAmount\tDate\n";
    cout << "----------------------------------\n";
    
    for (int i = 0; i < count; ++i) 
    {
        cout << expenses[i].category << "\t\t"
             << expenses[i].amount << "\t"
             << expenses[i].date << "\n";
    }
}

void sortExpenses(Expense* expenses, int count) 
{
    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = i + 1; j < count; ++j) 
        {
            if (expenses[i].amount > expenses[j].amount) 
            {
                Expense temp = expenses[j];
                expenses[j] = expenses[i];
                expenses[i] = temp;
            }
        }
    }
    cout << "Expenses sorted by amount.\n";
}

void searchExpense(const Expense* expenses, int count) 
{
    string searchCategory;
    cout << "Enter category to search: ";
    getline(cin, searchCategory);

    bool foundAtLeastOne = false;

    cout << "Expenses in category " << searchCategory << ":\n";

    for (int i = 0; i < count; ++i)
    {
        if (expenses[i].category == searchCategory) 
        {
            cout << "Amount: " << expenses[i].amount
                 << ", Date: " << expenses[i].date << "\n";
            foundAtLeastOne = true;
        }
    }

    if (!foundAtLeastOne) 
    {
        cout << "No expenses found in this category.\n";
    }
}

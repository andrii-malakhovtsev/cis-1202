// Andrii Malakhovtsev
// CIS 1202 501
// November 24, 2024

#include "Publication.h"
#include <fstream>
#include <iomanip>

void getPublicationInfo(Publication&);
void getPublications(Publication[], int&);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

int main()
{
	const int MAX_PUBLICATIONS = 100;
	Publication publications[MAX_PUBLICATIONS];
	int numPublications = 0;

	getPublications(publications, numPublications);

	int choice;
	do {
		choice = getMenuChoice();

		switch (choice)
		{
		case 1:
			showPublications(publications, numPublications);
			break;
		case 2:
			showTitles(publications, numPublications);
			break;
		case 3:
		{
			string title;
			cout << "Enter the title of the publication: ";
			cin.ignore();
			getline(cin, title);

			int index = findPublication(publications, numPublications, title);
			if (index != -1)
			{
				cout << "\nPublication found:\n";
				publications[index].displayInfo();
				cout << endl;
			}
			else
			{
				cout << "\nPublication not found.\n\n";
			}
			break;
		}
		case 4:
		{
			string title;
			cout << "Enter the title of the publication to check out: ";
			cin.ignore();
			getline(cin, title);

			int index = findPublication(publications, numPublications, title);
			if (index != -1)
			{
				publications[index].checkOut();
				cout << "\nChecked out successfully.\n\n";
			}
			else
			{
				cout << "\nPublication not found.\n\n";
			}
			break;
		}
		case 5:
		{
			string title;
			cout << "Enter the title of the publication to check in: ";
			cin.ignore();
			getline(cin, title);

			int index = findPublication(publications, numPublications, title);
			if (index != -1)
			{
				publications[index].checkIn();
				cout << "\nChecked in successfully.\n\n";
			}
			else
			{
				cout << "\nPublication not found.\n\n";
			}
			break;
		}
		case 6:
			cout << "\nExiting...\n";
			break;
		default:
			cout << "\nInvalid choice. Please, try again.\n\n";
		}
	} while (choice != 6);

	// End
	cout << endl << endl;
	system("pause");
	return 0;
}

void getPublicationInfo(Publication& publication)
{
	string title, publisher;
	double price;
	int year, type, stock;

	cout << "Enter title: ";
	getline(cin, title);
	cout << "Enter publisher: ";
	getline(cin, publisher);
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter type (0 = Book, 1 = Magazine, 2 = Newspaper, 3 = Audio, 4 = Video): ";
	cin >> type;
	cout << "Enter stock: ";
	cin >> stock;

	publication.storePublication(title, publisher, price, year, static_cast<PublicationType>(type), stock);
}

void getPublications(Publication list[], int& count)
{
	ifstream file("11publications.txt");
	if (!file)
	{
		cerr << "Error: Unable to open file.\n";
		exit(1);
	}

	string title, publisher;
	double price;
	int year, type, stock;

	while (getline(file, title))
	{
		getline(file, publisher);
		file >> price >> year >> type >> stock;
		file.ignore();
		list[count].storePublication(title, publisher, price, year, static_cast<PublicationType>(type), stock);
		count++;
	}
	file.close();
}

void showPublications(Publication list[], int count)
{
	cout << "\nList of all publications:\n\n";
	for (int i = 0; i < count; i++)
	{
		cout << "Publication #" << (i + 1) << ":\n";
		list[i].displayInfo();
		cout << endl;
	}
}

void showTitles(Publication list[], int count)
{
	cout << "\nAll publication titles:\n";
	for (int i = 0; i < count; i++)
	{
		cout << (i + 1) << ". " << list[i].getTitle() << endl;
	}
	cout << endl;
}

int findPublication(Publication list[], int count, string title)
{
	for (int i = 0; i < count; i++)
	{
		if (list[i].getTitle() == title)
		{
			return i;
		}
	}
	return -1;
}

int getMenuChoice()
{
	int choice;
	cout << "=== MENU ===\n";
	cout << "1. Display all publications\n";
	cout << "2. Display publication titles\n";
	cout << "3. Find a publication\n";
	cout << "4. Check out\n";
	cout << "5. Check in\n";
	cout << "6. Exit\n";
	cout << "Please, enter your choice: ";
	cin >> choice;
	return choice;
}

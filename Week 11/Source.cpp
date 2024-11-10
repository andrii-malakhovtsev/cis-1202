// Andrii Malakhovtsev
// CIS 1202 501
// November 9, 2024

#include "Publication.h"

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

int main()
{
	Publication publication;

	getPublicationInfo(publication);

	cout << "\nPublication Title: " << publication.getTitle() << endl;

	publication.checkOut();
	cout << "Stock after checkout: " << publication.getStock() << endl;

	publication.checkIn();
	cout << "Stock after check-in: " << publication.getStock() << endl;

	cout << "\nPublication Information:" << endl;
	publication.displayInfo();

	// End
	cout << endl << endl;
	system("pause");
	return 0;
}

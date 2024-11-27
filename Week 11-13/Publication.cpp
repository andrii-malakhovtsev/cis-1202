// Andrii Malakhovtsev
// CIS 1202 501
// November 9, 2024

#include "Publication.h"

Publication::Publication() : title(""), publisher(""), price(0.0), year(0), type(BOOK), stock(0) {}

void Publication::storePublication(string itemTitle, string itemPublisher,
	double itemPrice, int itemYear,
	PublicationType itemType, int itemStock)
{
	title = itemTitle;
	publisher = itemPublisher;
	price = itemPrice;
	year = itemYear;
	type = itemType;
	stock = itemStock;
}

void Publication::displayInfo() const
{
	cout << "Title: " << title << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Price: $" << price << endl;
	cout << "Year: " << year << endl;
	cout << "Type: " << type << endl;
	cout << "Stock: " << stock << endl;
}

void Publication::checkOut()
{
	if (stock > 0)
	{
		stock--;
	}
	else
	{
		cout << "Out of stock!" << endl;
	}
}

void Publication::checkIn()
{
	stock++;
}

string Publication::getTitle() const
{
	return title;
}

int Publication::getStock() const
{
	return stock;
}

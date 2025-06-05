#include <iostream>
#include <string>
using namespace std;

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication
{
private:
	string title;
	string publisher;
	double price;
	int year;
	PublicationType type;
	int stock;

public:
	Publication();
	void storePublication(string itemTitle, string itemPublisher, double itemPrice, 
		int itemYear, PublicationType itemType, int itemStock);
	void displayInfo() const;
	void checkOut();
	void checkIn();
	string getTitle() const;
	int getStock() const;
};

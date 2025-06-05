#include<iostream>
#include<cstring>
#include<string>

using namespace std;

enum suits { HEARTS, DIAMONDS, SPADES, CLUBS };
enum ranks { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct cards 
{
	suits suit;
	ranks rank;
};

void createDeck(cards[]);
void printDeck(cards[]);
string cardName(cards);
cards deal(cards[]);
string winner(cards, cards);

int main() 
{
    srand(time(NULL));

    cards deck[52];
    cards card1, card2;

    createDeck(deck);
    printDeck(deck);

    card1 = deal(deck);
    cout << "Card 1: " << cardName(card1) << endl;

    card2 = deal(deck);
    cout << "Card 2: " << cardName(card2) << endl;

    cout << "Winner: " << winner(card1, card2) << endl;

    // End
    cout << endl << endl;
    system("pause");
    return 0;
}

void createDeck(cards deck[]) 
{
    int index = 0;
    for (int suit = HEARTS; suit <= CLUBS; ++suit) 
    {
        for (int rank = TWO; rank <= ACE; ++rank) 
        {
            deck[index].suit = static_cast<suits>(suit);
            deck[index].rank = static_cast<ranks>(rank);
            ++index;
        }
    }
}

void printDeck(cards deck[]) 
{
    for (int i = 0; i < 52; ++i) 
    {
        cout << cardName(deck[i]) << endl;
    }
}

string cardName(cards card) 
{
    string rankNames[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
    string suitNames[] = { "Hearts", "Diamonds", "Spades", "Clubs" };

    return rankNames[card.rank] + " of " + suitNames[card.suit];
}


cards deal(cards deck[]) 
{
    int index = rand() % 52;
    return deck[index];
}

string winner(cards card1, cards card2) 
{
    if (card1.rank > card2.rank) 
    {
        return cardName(card1);
    }
    else if (card1.rank < card2.rank) 
    {
        return cardName(card2);
    }
    else 
    {
        return "Tie!";
    }
}
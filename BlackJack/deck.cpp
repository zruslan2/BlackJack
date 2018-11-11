#include "deck.h"

deck::deck()
{
	int counter = 0;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 13; j++)
		{
			cards.push_back(Card((mast)i, (nom)(j + 2)));
			counter++;
		}
	}
}

//void deck::print()
//{
//	for (int i = 0; i < cards.size();i++) {
//		cout << cards[i].getInfo() << endl;
//	}
//}

void deck::shuffle()
{
	srand(time(0));
	random_shuffle(begin(cards), end(cards));
}

Card deck::getNextCard()
{
	Card c = cards[0];
	cards.erase(begin(cards));
	return c;
}

void deck::addCard(const Card & c)
{
	cards.push_back(c);
}

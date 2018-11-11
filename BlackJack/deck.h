#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
class deck
{
	vector<Card> cards;
public:
	deck();
	//void print();
	void shuffle();
	Card getNextCard();
	int getCountCards() const {
		return cards.size();
	};

	void addCard(const Card&c);

};


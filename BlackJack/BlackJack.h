#pragma once
#include"deck.h"
//логика игры
class BlackJack
{
	int bet;
	int money;

	vector<Card> player;
	vector<Card> diller;

	deck deck_;

public:
	BlackJack(int money, int bet);
	static int getNom(const Card &c);

	bool startRound();
	Card getCard();

	const vector<Card> & getPlayerCards() const { return player; }
	const vector<Card> & getDillerCards() const { return diller; }

	static int getPoints(const vector<Card> & d);

	int getBet();
	int getMoney();
	void setBet(int bet);
	void addMoney(int money);

	bool isGameStart()const;
};




#pragma once
#include"deck.h"
//логика игры
class BlackJack
{
	int bet;
	int money;

	vector<Card> player;
	vector<Card> diller;

	bool playerStoped=false;
	bool dillerStoped=false;
	deck deck_;

public:
	BlackJack(int money, int bet);
	static int getNom(const Card &c);

	bool startRound();
	Card getCard();

	void pushCardForPlayer();
	void pushCardForDiller();

	void dillerSteps();

	const vector<Card> & getPlayerCards() const { return player; }
	const vector<Card> & getDillerCards() const { return diller; }

	static int getPoints(const vector<Card> & d);

	int getBet();
	int getMoney();
	void setBet(int bet);
	void setPlayerStoped(bool b);
	void setDillerStoped(bool b);
	bool getPlayerStoped()const { return playerStoped; }
	bool getDillerStoped()const { return dillerStoped; }
	void addMoney(int money);


	void eraseCard();
	bool isGameStart()const;
	wstring resultGame();
};




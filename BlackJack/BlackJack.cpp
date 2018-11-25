#include "BlackJack.h"


BlackJack::BlackJack(int money, int bet)
{
	this->money = money;
	this->bet = bet;
	deck_.shuffle();
}

int BlackJack::getNom(const Card & c)
{
	int res = (int)c.getNom();
	if (res < 10)
		return res;
	if (res < 14)
		return  10;
	if (res == 14)
		return 11;
}

bool BlackJack::startRound()
{
	if (bet > money)return 0;

	money -= bet;

	for (size_t i = 0; i < 2; i++)
	{
		player.push_back(this->getCard());
		diller.push_back(this->getCard());
	}
}

Card BlackJack::getCard()
{
	if (deck_.getCountCards() == 0)
	{
		deck_ = deck();
		deck_.shuffle();
	}
	return deck_.getNextCard();

}

void BlackJack::pushCardForPlayer()
{
	player.push_back(this->getCard());	
}

void BlackJack::pushCardForDiller()
{
	diller.push_back(this->getCard());
}

void BlackJack::dillerSteps()
{
	while (true)
	{
		if (getPoints(getDillerCards()) < 18)
			pushCardForDiller();
		else
			break;				
	}	
	setDillerStoped(true);
}

int BlackJack::getPoints(const vector<Card>& d)
{
	int res = 0;
	for (size_t i = 0; i < d.size(); i++)
	{
		res += getNom(d[i]);
	}
	return res;
}

int BlackJack::getBet()
{
	return bet;
}

int BlackJack::getMoney()
{
	return money;
}

void BlackJack::setBet(int bet)
{
	this->bet = bet;
}

void BlackJack::setPlayerStoped(bool b)
{
	this->playerStoped = b;
}

void BlackJack::setDillerStoped(bool b)
{
	this->dillerStoped = b;
}

void BlackJack::addMoney(int money)
{
	this->money += money;
}

void BlackJack::eraseCard()
{
	player.clear();
	diller.clear();
}

bool BlackJack::isGameStart() const
{
	return player.size() >= 2;
}

wstring BlackJack::resultGame()
{
	wstring res=L"";
	if (getPoints(getPlayerCards()) == 21 && getPoints(getDillerCards()) != 21)
	{
		res = L"Congratulations, You win!!!";
		money += 1.5*bet;
		return res;
	}
	if (getPoints(getPlayerCards()) > 21)
	{
		res = L"You loss :-(";
		return res;
	}		
	if (getPoints(getPlayerCards()) <= 21 && getPoints(getDillerCards()) > 21)
	{
		res = L"Congratulations, You win!!!";
		money += 1.5*bet;
		return res;
	}
	if (getPoints(getPlayerCards()) > getPoints(getDillerCards()))
	{
		res = L"Congratulations, You win!!!";
		money += 1.5*bet;
		return res;
	}
	if (getPoints(getPlayerCards()) < getPoints(getDillerCards()))
	{
		res = L"You loss :-(";
		return res;
	}
	if (getPoints(getPlayerCards()) == getPoints(getDillerCards()))
	{
		res = L"Congratulations, draw!!!";
		money += 1*bet;
		return res;
	}
	return res;
}

#pragma once
#include <string>
#include <map>
using namespace std;

enum mast {
	kresti,
	chervy,
	piki,
	bubi
};

enum nom {
	two = 2, three, four, five, six, seven,
	eight, nine, ten, jack,
	queen, king, ace, jocker
};

class Card
{
	mast m;
	nom n;
	static map<nom, string> value;
public:
	Card(mast m1, nom n1);
	mast getMast()const { return this->m; }
	nom getNom()const { return this->n; }
	string getSMast()const;
	string getSNom()const;
	string getInfo()const;
};




#include "Card.h"

map<nom, string> Card::value =
{ pair<nom,string>(two, "2"),
pair<nom,string>(three, "3") ,
pair<nom, string>(four,"4"),
pair<nom,string>(five,"5"),
pair<nom,string>(six, "6"),
pair<nom,string>(seven,	"7"),
pair<nom,string>(eight, "8"),
pair<nom,string>(nine, "9"),
pair<nom,string>(ten, "10"),
pair<nom,string>(jack,	"jack"),
pair<nom,string>(queen, "queen"),
pair<nom,string>(king, "king"),
pair<nom,string>(ace,"ace"),
pair<nom,string>(jocker,"jocker") };


Card::Card(mast m1, nom n1)
{
	this->m = m1;
	this->n = n1;
}

string Card::getSMast() const
{
	string str;
	switch (this->m)
	{
	case mast::kresti:
		str = "kresti";
		break;
	case mast::chervy:
		str = "chervy";
		break;
	case mast::piki:
		str = "piki";
		break;
	case mast::bubi:
		str = "bubi";
		break;
	}
	return str;
}

string Card::getSNom() const
{
	return value[n];
}

string Card::getInfo() const
{
	string str = getSNom() + " ";
	if (this->n == nom::jocker)
		if (m == mast::bubi || m == mast::chervy)
			str += "red";
		else
			str += "black";
	else
		str += getSMast();
	return str;
}

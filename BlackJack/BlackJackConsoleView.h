#pragma once
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include "BlackJack.h"
#include <Windows.h>


using namespace std;

class BlackJackConsoleView
{
	BlackJack game;
public:
	BlackJackConsoleView();
	void start();
	void printScreen();
	void printMenu(int x, int y);
	void printAddMoney(int x, int y);
	void printSetBet(int x, int y);

	void red();
	void black();
	void green();
	void GotoXY(int X, int Y);
	void top();
	void bottom();
	void ViewCard(int m, int n, int x, int y);
};




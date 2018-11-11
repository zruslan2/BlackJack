#include "BlackJackConsoleView.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

BlackJackConsoleView::BlackJackConsoleView()
	:game(0, 0)
{
	int x = 20, y = 5;
	black();
	GotoXY(x, y);
	wcout << "Hello!";
	y++;
	GotoXY(x, y);
	wcout << "---------------";
	y++;	
	printAddMoney(x,y);
	y++;
	GotoXY(x, y);
	wcout << "---------------";
	y++;	
	printSetBet(x,y);	
}

void BlackJackConsoleView::start()
{
	int choice = 0;
	int x = 4, y = 33;
	while (1) {
		system("cls");
		printScreen();
		while (true)
		{
			GotoXY(x, y);
			wcin >> choice;
			if (!game.isGameStart())
			{
				if (choice > 0 && choice < 4) break;
			}
			if (game.isGameStart())
			{
				if (choice > 0 && choice < 5) break;
			}
		}
		
		//если игры нет
		if (!game.isGameStart()) {
			if (choice == 4) break;

			if (choice == 1) {
				game.startRound();
				continue;
			}
			if (choice == 2) {
				printAddMoney(x,y);
				continue;
			}
			if (choice == 3) {
				printSetBet(x,y);
				continue;
			}


		}

		if (game.isGameStart()) {
			//1 - get new Card 2 - stop 3 - exit
			//int result = game.checkRound();
			//if (result == 1) continue;
			//if (result == 2) {

			//}
			////
			//}

		}
		system("cls");
		cout << "Good bye!\n";
	}
}

	void BlackJackConsoleView::printScreen()
	{
		int x=4, y=2;
		black();
		GotoXY(x, y);
		wcout << "Hello!";
		y++;
		GotoXY(x, y);
		wcout << "------------------------------";
		y++;
		GotoXY(x, y);
		wcout << "diller\'s cards\n";
		y++;
		for (size_t i = 0; i < game.getDillerCards().size(); i++)
		{
			ViewCard(game.getDillerCards()[i].getMast(), game.getDillerCards()[i].getNom(), x, y);
			x += 8;
		}
		y+=8;
		x = 4;
		black();
		GotoXY(x, y);
		wcout << "Diller\'s points = " << game.getPoints(game.getDillerCards());
		y++;
		GotoXY(x, y);
		y++;
		GotoXY(x, y);
		wcout << "------------------------------";
		y++;
		GotoXY(x, y);
		wcout << "Your cards ";
		y++;
		for (size_t i = 0; i < game.getPlayerCards().size(); i++)
		{
			ViewCard(game.getPlayerCards()[i].getMast(), game.getPlayerCards()[i].getNom(), x, y);
			x += 8;
		}
		y += 8;
		x = 4;
		black();
		GotoXY(x, y);
		wcout << "Your points = " << game.getPoints(game.getPlayerCards());
		y++;
		GotoXY(x, y);
		wcout << "Your money = " << game.getMoney();
		y++;
		GotoXY(x, y);
		wcout << "Your bet = " << game.getBet();
		y++;
		GotoXY(x, y);
		wcout << "------------------------------";
		y++;
		GotoXY(x, y);
		printMenu(x,y);
	}

	void BlackJackConsoleView::printMenu(int x, int y)
	{
		//если игра началась
		if (game.isGameStart()) {
			GotoXY(x, y);
			wcout << "1 - get new Card";
			y++;
			GotoXY(x, y);
			wcout << "2 - stop";
			y++;
			GotoXY(x, y);
			wcout << "3 - exit";
			y++;
			GotoXY(x, y);
		}
		else {
			//нет нового раунда
			GotoXY(x, y);
			wcout << "1 - new game";
			y++;
			GotoXY(x, y);
			wcout << "2- Add money";
			y++;
			GotoXY(x, y);
			wcout << "3 - Set Bet";
			y++;
			GotoXY(x, y);
			wcout << "4 - exit";
			y++;
			GotoXY(x, y);
		}
	}

	void BlackJackConsoleView::printAddMoney(int x, int y)
	{
		GotoXY(x, y);
		wcout << "Add money ";
		int m;
		wcin >> m;
		game.addMoney(m);
	}

	void BlackJackConsoleView::printSetBet(int x, int y)
	{
		GotoXY(x, y);
		wcout << "Set bet ";
		int b;
		wcin >> b;
		game.setBet(b);
	}

	void BlackJackConsoleView::red()
	{
		SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	}

	void BlackJackConsoleView::black()
	{
		SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	}

	void BlackJackConsoleView::green()
	{
		SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 11));
	}

	void BlackJackConsoleView::GotoXY(int X, int Y)
	{
		COORD coord = { X, Y };
		SetConsoleCursorPosition(hConsole, coord);
	}

	void BlackJackConsoleView::top()
	{
		wcout << L"\u250c";
		for (size_t i = 0; i < 5; i++)
		{
			wcout << L"\u2500";
		}
		wcout << L"\u2510\n";
	}

	void BlackJackConsoleView::bottom()
	{
		wcout << L"\u2514";
		for (size_t i = 0; i < 5; i++)
		{
			wcout << L"\u2500";
		}
		wcout << L"\u2518\n";
	}

	void BlackJackConsoleView::ViewCard(int m, int n, int x, int y)
	{
		wstring mast;
		if (m == 0)
		{
			mast = L"\u2663";
			black();
		}
		else if (m == 1)
		{
			mast = L"\u2665";
			red();
		}
		else if (m == 2)
		{
			mast = L"\u2660";
			black();
		}
		else if (m == 3)
		{
			mast = L"\u2666";
			red();
		}
		wstring Cstr = L"\u2502\     \u2502\n";
		wstring Jstr = L"\u2502\jack \u2502\n";
		wstring Qstr = L"\u2502\queen\u2502\n";
		wstring Kstr = L"\u2502\king \u2502\n";
		wstring Astr = L"\u2502\ ace \u2502\n";
		wstring str1 = L"\u2502\  ";
		str1 += mast;
		str1 += L"  \u2502";
		wstring str2 = L"\u2502";
		str2 += mast;
		str2 += L"   ";
		str2 += mast;
		str2 += L"\u2502";

		if (n == 2)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << str1;
			for (size_t i = 0; i < 3; i++)
			{
				y++;
				GotoXY(x, y);
				wcout << Cstr;
			}
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 3)
		{
			GotoXY(x, y);
			top();
			for (size_t i = 0; i < 2; i++)
			{
				y++;
				GotoXY(x, y);
				wcout << str1;
				y++;
				GotoXY(x, y);
				wcout << Cstr;
			}
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 4)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << str2;
			for (size_t i = 0; i < 3; i++)
			{
				y++;
				GotoXY(x, y);
				wcout << Cstr;
			}
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 5)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 6)
		{
			GotoXY(x, y);
			top();
			for (size_t i = 0; i < 2; i++)
			{
				y++;
				GotoXY(x, y);
				wcout << str2;
				y++;
				GotoXY(x, y);
				wcout << Cstr;
			}
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 7)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 8)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 9)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 10)
		{
			GotoXY(x, y);
			top();
			for (size_t i = 0; i < 5; i++)
			{
				y++;
				GotoXY(x, y);
				wcout << str2;
			}
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 11)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << Jstr;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 12)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << Qstr;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 13)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << Kstr;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			bottom();
		}
		else if (n == 14)
		{
			GotoXY(x, y);
			top();
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			wcout << Astr;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
			y++;
			GotoXY(x, y);
			bottom();
		}
	}

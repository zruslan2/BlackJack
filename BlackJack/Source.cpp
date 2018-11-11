#include "BlackJackConsoleView.h"

void main() {

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	system("color F4");

	BlackJackConsoleView v;
	v.start();	
	system("pause");
}